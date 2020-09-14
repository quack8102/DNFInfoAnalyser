#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cvalgorithm.h"
#include <QScreen>
#include <Windows.h>
#include <QFile>
#include <String>
#include <QTemporaryDir>
#include <QTextStream>
#include <QMessageBox>
#include <QFileInfo>
#include <QFileDialog>
#include <QDebug>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

QVector<HWND> vec;

Mat templateImg, selfInfoImg, classNameImg, charImg;
QVector<ClassData> classVec;
QVector<LayoutData> selfVec, otherVec;
QVector<SetData> setVec;
QVector<CharData> charVec;
QVector<QVector<EquipmentData> > equipmentInfoVec, weaponInfoVec;
QVector<Mat> equipmentImgVec, weaponImgVec;
HWND currentHWND;
bool isHotkey;

const int matchIconPosX = 82, matchIconPosY = 64, userInfoWidth = 282, userInfoHeight = 425;

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow) {
    isHotkey = true;
    ui->setupUi(this);

    readImg(templateImg, "://resources/match_template.png");
    readImg(selfInfoImg, "://resources/selfinfo.png");
    readImg(classNameImg, "://resources/class/class.png");
    readImg(charImg, "://resources/char/char.png");
    readCSV(classVec, "://resources/class/class.csv");
    readCSV(selfVec, "://resources/selflayout.csv");
    readCSV(otherVec, "://resources/otherlayout.csv");
    readCSV(setVec, "://resources/setname.csv");
    readCSV(charVec, "://resources/char/char.csv");

    addWeapon("demoniclancer"); // 0
    addWeapon("fighter"); // 1
    addWeapon("gunblader"); // 2
    addWeapon("gunner"); // 3
    addWeapon("mage"); // 4
    addWeapon("priest"); // 5
    addWeapon("swordman"); // 6
    addWeapon("thief"); // 7

    addEquipment("neck"); // 0
    addEquipment("coat"); // 1
    addEquipment("pants"); // 2
    addEquipment("belt"); // 3
    addEquipment("shoes"); // 4
    // 添加武器 5
    equipmentInfoVec.push_back(weaponInfoVec[0]);
    equipmentImgVec.push_back(weaponImgVec[0]);
    //
    addEquipment("title"); // 6
    addEquipment("bracelet"); // 7
    addEquipment("necklace"); // 8
    addEquipment("support"); // 9
    addEquipment("ring"); // 10
    addEquipment("earring"); // 11
    addEquipment("magicstone"); // 12

    mainTray = new QSystemTrayIcon(this);
    mainMenu = new QMenu(this);
    windowMenu = new QMenu(this);
    enableAction = new QAction(this);
    grabAction = new QAction(this);
    openAction = new QAction(this);
    setAction = new QAction(this);
    exitAction = new QAction(this);

    mainMenu->addMenu(windowMenu);
    mainMenu->addAction(enableAction);
    mainMenu->addSeparator();
    mainMenu->addAction(grabAction);
    mainMenu->addAction(openAction);
    mainMenu->addSeparator();
    mainMenu->addAction(setAction);
    mainMenu->addSeparator();
    mainMenu->addAction(exitAction);

    windowMenu->setTitle(tr("窗口"));
    enableAction->setText(tr("关闭热键"));
    connect(enableAction, &QAction::triggered, [ = ]() {
        if (isHotkey) {
            isHotkey = false;
            enableAction->setText(tr("打开热键"));
            mainTray->showMessage("DNF面板自动分析", //消息窗口标题
                                  "热键已关闭", //消息内容
                                  QSystemTrayIcon::MessageIcon::Information, //消息窗口图标
                                  1000); //消息窗口显示时长
        } else {
            isHotkey = true;
            enableAction->setText(tr("关闭热键"));
            mainTray->showMessage("DNF面板自动分析", //消息窗口标题
                                  "热键已开启", //消息内容
                                  QSystemTrayIcon::MessageIcon::Information, //消息窗口图标
                                  1000); //消息窗口显示时长
        }
    });
    grabAction->setText(tr("从游戏画面分析"));
    connect(grabAction, &QAction::triggered, this, &MainWindow::actionActivated);
    openAction->setText(tr("从截图文件分析..."));
    connect(openAction, &QAction::triggered, this, &MainWindow::on_openBtn_clicked);
    setAction->setText(tr("设置..."));
    connect(setAction, &QAction::triggered, [ = ]() {
        QMessageBox::information(NULL, "DNF面板自动分析", "更多功能开发中...\n作者colg账号：addonesec");
    });
    exitAction->setText(tr("退出"));
    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);

    mainTray->setContextMenu(mainMenu);
    mainTray->setIcon(QIcon("://resources/icon.png"));
    mainTray->setToolTip(tr("DNF面板自动分析"));
    mainTray->show();
    connect(mainTray, &QSystemTrayIcon::activated, this, &MainWindow::activeTray);

    currentHWND = NULL;
    refresh();

    mainTray->showMessage("DNF面板自动分析", //消息窗口标题
                          "程序已启动", //消息内容
                          QSystemTrayIcon::MessageIcon::Information, //消息窗口图标
                          1000); //消息窗口显示时长
}

void MainWindow::activeTray(QSystemTrayIcon::ActivationReason reason) {
    if (reason == QSystemTrayIcon::Context) {
        refresh();
        mainMenu->show();
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::addDNF(const HWND &hwnd) {
    //qDebug() << hwnd << endl;
    if (hwnd == NULL) return;
    vec.push_back(hwnd);
    ui->comboBox->addItem(QString::asprintf("Window %d", vec.size()));
}

void MainWindow::refresh() {
    ui->comboBox->clear();
    vec.clear();
    windowMenu->clear();
    HWND hwnd = FindWindow(NULL, L"地下城与勇士");
    addDNF(hwnd);
    while (hwnd != NULL) {
        hwnd = FindWindowEx(NULL, hwnd, NULL, L"地下城与勇士");
        addDNF(hwnd);
    }
    if (vec.size() == 0) {
        ui->grabButton->setEnabled(false);
        ui->topButton->setEnabled(false);
    } else {
        ui->grabButton->setEnabled(true);
        ui->topButton->setEnabled(true);
    }
    std::sort(vec.begin(), vec.end());
    if (vec.empty()) {
        currentHWND = NULL;
        QAction *tmpAction = new QAction(tr("无"));
        windowMenu->addAction(tmpAction);
        tmpAction->setEnabled(false);
    } else {
        bool tmpFlag = false;
        int tot = 0;
        for (HWND v : vec)
            if (currentHWND != NULL && v == currentHWND) {
                tmpFlag = true;
                break;
            }
        if (!tmpFlag) currentHWND = vec.at(0);
        for (HWND v : vec) {
            ++tot;
            QAction *tmpAction;
            if (v == currentHWND) {
                tmpAction = new QAction(QString::asprintf("Window %d √", tot));
            } else {
                tmpAction = new QAction(QString::asprintf("Window %d", tot));
            }
            windowMenu->addAction(tmpAction);
            connect(tmpAction, &QAction::triggered, [ = ]() {
                currentHWND = v;
                SetForegroundWindow(v);
            });
        }
    }
}

template <typename T>
void MainWindow::readCSV(QVector<T> &vec, const QString &path) {
    vec.clear();
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        //qDebug() << "Can't open the file!" << endl;
        QMessageBox::critical(NULL, "错误", "资源文件读取失败");
    } else {
        QTextStream stream(&file);
        //stream.setCodec("UTF-8");
        forever {
            QString line = stream.readLine();
            if (line.isEmpty()) break;
            vec.push_back(T(line.split(",")));
        }
        file.close();
    }
}

void MainWindow::readImg(Mat &inMat, const QString &path) {
    QTemporaryDir tempDir;
    QFileInfo fileinfo(path);
    if (tempDir.isValid()) {
        const QString tempFile = tempDir.path() + "/" + fileinfo.fileName();
        if (QFile::copy(path, tempFile)) {
            try {
                inMat = imread(tempFile.toStdString());
            } catch (cv::Exception &e) {
                QMessageBox::critical(NULL, "错误", "资源文件解包失败");
            }
        } else {
            QMessageBox::critical(NULL, "错误", "资源文件解包失败");
        }
    } else {
        QMessageBox::critical(NULL, "错误", "资源文件解包失败");
    }
}

void MainWindow::addEquipment(const QString &name) {
    QVector<EquipmentData> tempVec;
    Mat tempImg;
    readImg(tempImg, "://resources/equipment/" + name + "/" + name + ".png");
    readCSV(tempVec, "://resources/equipment/" + name + "/" + name + ".csv");
    equipmentInfoVec.push_back(tempVec);
    equipmentImgVec.push_back(tempImg);
}

void MainWindow::addWeapon(const QString &name) {
    QVector<EquipmentData> tempVec;
    Mat tempImg;
    readImg(tempImg, "://resources/weapon/" + name + "/" + name + ".png");
    readCSV(tempVec, "://resources/weapon/" + name + "/" + name + ".csv");
    weaponInfoVec.push_back(tempVec);
    weaponImgVec.push_back(tempImg);
}

void MainWindow::on_refreshButton_clicked() {
    refresh();
}

void MainWindow::showChildWindow(const Mat &srcImg) {
    try {
        Point matchLocation = CVA::matchTemplate(srcImg, templateImg);
        Rect selectInfo = Rect(matchLocation.x - matchIconPosX, matchLocation.y - matchIconPosY, userInfoWidth, userInfoHeight);
        Mat infoImg = srcImg(selectInfo);
        UserInfoWindow *cw = new UserInfoWindow(NULL, infoImg, mainTray);
        cw->setWindowFlags(cw->windowFlags() | Qt::WindowStaysOnTopHint);
        cw->show();
    } catch (cv::Exception &e) {
        //QMessageBox::warning(NULL, "分析失败", "检测不到角色面板");
        mainTray->showMessage("分析失败", //消息窗口标题
                              "检测不到角色面板", //消息内容
                              QSystemTrayIcon::MessageIcon::Warning, //消息窗口图标
                              1000); //消息窗口显示时长
    }
}

void MainWindow::on_grabButton_clicked() {
    grabDNFWindow(vec[ui->comboBox->currentIndex()]);
}

void MainWindow::grabDNFWindow(const HWND &hwnd) {
    if (hwnd == NULL) {
        //QMessageBox::critical(NULL, "错误", "当前未开启DNF窗口");
        mainTray->showMessage("错误", //消息窗口标题
                              "当前未开启DNF窗口", //消息内容
                              QSystemTrayIcon::MessageIcon::Warning, //消息窗口图标
                              1000); //消息窗口显示时长
        return;
    }
    QScreen *screen = QGuiApplication::primaryScreen();
    Mat tempMat;
    try {
        tempMat = CVA::QPixmapToCvMat(screen->grabWindow(WId(hwnd)));
    } catch (cv::Exception &e) {
        //QMessageBox::critical(NULL, "错误", "截图失败");
        mainTray->showMessage("错误", //消息窗口标题
                              "截图失败", //消息内容
                              QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                              1000); //消息窗口显示时长
    }
    showChildWindow(tempMat);
}

void MainWindow::hotkeyActivated() {
    if (isHotkey) {
        actionActivated();
    }
}

void MainWindow::actionActivated() {
    if (currentHWND == NULL) refresh();
    grabDNFWindow(currentHWND);
}

void MainWindow::on_topButton_clicked() {
    HWND hwnd = vec[ui->comboBox->currentIndex()];
    SetForegroundWindow(hwnd);
}

void MainWindow::on_openBtn_clicked() {
    QString fileName = QFileDialog::getOpenFileName(
                           this,
                           tr("打开图片"),
                           "./",
                           tr("图片文件(*.png *.jpeg *.jpg *.bmp)"));
    if (!fileName.isEmpty()) {
        QTemporaryDir tempDir;
        QFileInfo fileinfo(fileName);
        if (tempDir.isValid()) {
            const QString tempFile = tempDir.path() + "/openimg" + fileinfo.suffix();
            if (QFile::copy(fileName, tempFile)) {
                Mat tempMat;
                try {
                    tempMat = imread(tempFile.toStdString());
                } catch (cv::Exception &e) {
                    //QMessageBox::critical(NULL, "错误", "文件打开失败");
                    mainTray->showMessage("错误", //消息窗口标题
                                          "文件打开失败", //消息内容
                                          QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                                          1000); //消息窗口显示时长
                }
                showChildWindow(tempMat);
            } else {
                //QMessageBox::critical(NULL, "错误", "文件打开失败");
                mainTray->showMessage("错误", //消息窗口标题
                                      "文件打开失败", //消息内容
                                      QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                                      1000); //消息窗口显示时长
            }
        } else {
            //QMessageBox::critical(NULL, "错误", "文件打开失败");
            mainTray->showMessage("错误", //消息窗口标题
                                  "文件打开失败", //消息内容
                                  QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                                  1000); //消息窗口显示时长
        }
    }
}
