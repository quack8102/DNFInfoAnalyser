#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cvalgorithm.h"
#include "settingdata.h"
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
#include <QSize>
#include <QPen>
#include <QFont>
#include <QPainter>
#include <opencv2/highgui/highgui.hpp>
#include <QDesktopServices>
#include "settingdata.h"

using namespace cv;

QVector<HWND> vec;

Mat templateImg, selfInfoImg, classNameImg, charImg, bracketL, bracketR;
QVector<ClassData> classVec;
QVector<LayoutData> selfVec, otherVec;
QVector<SetData> setVec;
QVector<CharData> charVec;
QVector<QVector<EquipmentData> > equipmentInfoVec, weaponInfoVec;
QVector<Mat> equipmentImgVec, weaponImgVec;
HWND currentHWND;
bool isHotkey;

const int classWidth = 96, classHeight = 14, charWidth = 12, charHeight = 14;
const int titleWidth = 49, titleHeight = 14;

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow) {
    isHotkey = true;
    sp = NULL;

    ui->setupUi(this);

    readCSV(classVec, "://resources/class.csv");
    readCSV(selfVec, "://resources/selflayout.csv");
    readCSV(otherVec, "://resources/otherlayout.csv");
    readCSV(setVec, "://resources/setname.csv");
    readCSV(charVec, "://resources/char/char.csv");

    readImg(templateImg, "://resources/match_template.png");
    readImg(charImg, "://resources/char/char.png");

    try {
        QImage classNameQImg(classWidth, 61 * classHeight, QImage::Format_RGB32);
        classNameQImg.fill(qRgb(0, 0, 0));
        QPainter painter(&classNameQImg);
        painter.setCompositionMode(QPainter::CompositionMode_Source);
        int totHeight = 0;
        for (ClassData cd : classVec) {
            QImage nameImg = drawText("[" + cd.name + "]");
            painter.drawImage((classWidth - nameImg.width() + 1) / 2, totHeight + 1, nameImg);
            totHeight += classHeight;
        }
        classNameImg = CVA::QImageToCvMat(classNameQImg);
        QImage selfInfoQImg(titleWidth, titleHeight, QImage::Format_RGB32);
        selfInfoQImg.fill(qRgb(0, 0, 0));
        QPainter painter2(&selfInfoQImg);
        painter2.drawImage(1, 1, drawText(tr("个人信息")));
        selfInfoImg = CVA::QImageToCvMat(selfInfoQImg);
        {
            QImage tmpImg = drawText(tr("["));
            QImage tmpImg2(tmpImg.width() + 2, tmpImg.height() + 2, QImage::Format_RGB32);
            tmpImg2.fill(qRgb(0, 0, 0));
            QPainter paer(&tmpImg2);
            paer.drawImage(1, 1, tmpImg);
            bracketL = CVA::QImageToCvMat(tmpImg2);
        }
        {
            QImage tmpImg = drawText(tr("]"));
            QImage tmpImg2(tmpImg.width() + 2, tmpImg.height() + 2, QImage::Format_RGB32);
            tmpImg2.fill(qRgb(0, 0, 0));
            QPainter paer(&tmpImg2);
            paer.drawImage(1, 1, tmpImg);
            bracketR = CVA::QImageToCvMat(tmpImg2);
        }
    } catch (cv::Exception &e) {
        QMessageBox::critical(NULL, "错误", "资源文件解包失败");
    }

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

    SettingData::readfile();
    SettingData::shortcut = new MyGlobalShortCut(SettingData::hotkeyStr, this);
    connect(SettingData::shortcut, SIGNAL(activated()), this, SLOT(hotkeyActivated()));
    SettingData::mw = this;

    mainTray = new QSystemTrayIcon(this);
    mainMenu = new QMenu(this);
    windowMenu = new QMenu(this);
    grabAction = new QAction(this);
    openAction = new QAction(this);
    setAction = new QAction(this);
    updateAction = new QAction(this);
    exitAction = new QAction(this);

    mainMenu->addMenu(windowMenu);
    mainMenu->addSeparator();
    mainMenu->addAction(grabAction);
    mainMenu->addAction(openAction);
    mainMenu->addSeparator();
    mainMenu->addAction(setAction);
    mainMenu->addAction(updateAction);
    mainMenu->addSeparator();
    mainMenu->addAction(exitAction);

    windowMenu->setTitle(tr("窗口"));
    grabAction->setText(tr("从游戏画面分析"));
    connect(grabAction, &QAction::triggered, this, &MainWindow::actionActivated);
    openAction->setText(tr("从截图文件分析..."));
    connect(openAction, &QAction::triggered, this, &MainWindow::on_openBtn_clicked);
    setAction->setText(tr("设置..."));
    connect(setAction, &QAction::triggered, [ = ]() {
        if (sp == NULL) {
            sp = new SettingPanel(NULL);
            connect(sp, SIGNAL(windowClosed()), this, SLOT(childWindowClosed()));
            sp->show();
        } else {
            sp->activateWindow();
            sp->setWindowState((sp->windowState() & ~Qt::WindowMinimized) | Qt::WindowActive);
        }
    });
    updateAction->setText(tr("检查更新..."));
    connect(updateAction, &QAction::triggered, [ = ]() {
        QDesktopServices::openUrl(QUrl(QLatin1String("https://github.com/quack8102/DNFInfoAnalyser")));
    });
    exitAction->setText(tr("退出"));
    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);

    mainTray->setContextMenu(mainMenu);
    mainTray->setIcon(QIcon("://resources/icon.png"));
    mainTray->setToolTip(tr("DNF面板自动分析 v1.0.0"));
    mainTray->show();
    connect(mainTray, &QSystemTrayIcon::activated, this, &MainWindow::activeTray);

    currentHWND = NULL;
    refresh();

    mainTray->showMessage("DNF面板自动分析", //消息窗口标题
                          "程序已启动", //消息内容
                          QSystemTrayIcon::MessageIcon::Information, //消息窗口图标
                          1000); //消息窗口显示时长
}

void MainWindow::childWindowClosed() {
    delete sp;
    sp = NULL;
}

QImage MainWindow::drawChar(const QString &str, const QImage &triangle) {
    QFont font;
    font.setFamily("宋体");
    font.setPixelSize(12);
    QVector<QImage> imgVec;
    int tot = 0;
    for (QChar c : str) {
        QSize size(charWidth, charHeight);
        QImage image(size, QImage::Format_RGB32);
        image.fill(qRgb(0, 0, 0));
        QPainter painter(&image);
        painter.setCompositionMode(QPainter::CompositionMode_Source);
        QPen pen = painter.pen();
        pen.setColor(Qt::white);
        painter.setPen(pen);
        painter.setFont(font);
        painter.drawText(image.rect(), Qt::AlignCenter, c);
        imgVec.push_back(image);
        tot += charWidth;
    }
    QSize size(tot + triangle.width(), charHeight);
    QImage image(size, QImage::Format_RGB32);
    image.fill(qRgb(0, 0, 0));
    QPainter painter(&image);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    tot = 0;
    for (QImage img : imgVec) {
        painter.drawImage(tot, 0, img);
        tot += charWidth;
    }
    painter.drawImage(tot, 1, triangle);
    return image;
}

QImage MainWindow::drawText(const QString &str) {
    QFont font;
    font.setFamily("宋体");
    font.setPixelSize(12);
    QFontMetrics fm(font);
    QVector<QImage> imgVec;
    int tot = 0;
    for (QChar c : str) {
        QSize size(fm.width(c), fm.height());
        QImage image(size, QImage::Format_RGB32);
        image.fill(qRgb(0, 0, 0));
        QPainter painter(&image);
        painter.setCompositionMode(QPainter::CompositionMode_Source);
        QPen pen = painter.pen();
        pen.setColor(Qt::white);
        painter.setPen(pen);
        painter.setFont(font);
        painter.drawText(image.rect(), Qt::AlignAbsolute, c);
        QRect qr = fm.tightBoundingRect(c);
        imgVec.push_back(image.copy(QRect(qr.x(), 0, qr.width(), fm.height())));
        tot += qr.width() + 1;
    }
    QSize size(tot - 1, fm.height());
    QImage image(size, QImage::Format_RGB32);
    image.fill(qRgb(0, 0, 0));
    QPainter painter(&image);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    tot = 0;
    for (QImage img : imgVec) {
        painter.drawImage(tot, 0, img);
        tot += img.width() + 1;
    }
    return image;
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

void MainWindow::showChildWindow(const Mat &srcImg, bool mode) {
    new UserInfoWindow(NULL, srcImg, mainTray, mode);
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
    showChildWindow(tempMat, true);
}

void MainWindow::hotkeyActivated() {
    if (SettingData::isHotkey) {
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
                showChildWindow(tempMat, false);
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
