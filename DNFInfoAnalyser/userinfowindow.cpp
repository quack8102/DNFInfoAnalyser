#include "userinfowindow.h"
#include "ui_userinfowindow.h"
#include "cvalgorithm.h"
#include "csvdataparser.h"
#include "factory.h"
#include "equipment.h"
#include "settingdata.h"
#include <vector>
#include <QComboBox>
#include <QMessageBox>
#include <QPalette>
#include <QBitmap>
#include <QMouseEvent>
#include <QSize>
#include <QPen>
#include <QFont>
#include <QPainter>
#include <QDir>
#include <QDateTime>
#include <QJsonArray>
#include <QtConcurrent>
#include <QJsonDocument>
#include <QDesktopServices>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

extern QVector<ClassData> classVec;
extern Mat templateImg, buffBookImg, classNameImg, charImg;
extern QVector<LayoutData> selfVec, otherVec;
extern QVector<SetData> setVec;
extern QVector<CharData> charVec;
extern QVector<QVector<EquipmentData> > equipmentInfoVec, weaponInfoVec;
extern QVector<Mat> equipmentImgVec, weaponImgVec;


const int matchIconPosX = 82, matchIconPosY = 64, userInfoWidth = 282, userInfoHeight = 401;
const int classPosX = 64, classPosY = 195, classWidth = 170, classHeight = 14;
const int titlePosX = 108, titlePosY = 5, titleWidth = 49, titleHeight = 14;
const int iconWidth = 28, iconHeight = 28;
const int charWidth = 12, charHeight = 14;
const double PSNRthreshold = 10.0;

QRect UserInfoWindow::geo;
bool UserInfoWindow::firstFlag = true;

UserInfoWindow::UserInfoWindow(QWidget *parent, const cv::Mat &srcImg, QSystemTrayIcon *tray, bool mode) :
    QWidget(parent),
    ui(new Ui::UserInfoWindow),
    mainTray(tray),
    setCnt(51) {

    qInfo() << "Trying to load the UserInfoWindow. rows = " << srcImg.rows
            << ", cols = " << srcImg.cols << ", mode = " << mode;

    classMenu = NULL;
    pantsMenu = NULL;
    ringMenu = NULL;
    supportMenu = NULL;

    this->mode = mode;
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
    //setAttribute(Qt::WA_DeleteOnClose);

    if (!firstFlag) setGeometry(geo);

    QPixmap bgImages("://resources/bg.png");
    QPalette bgPalette = this->palette();
    bgPalette.setBrush(QPalette::Background, bgImages);
    this->setPalette(bgPalette);

    setMask(bgImages.mask());

    qs.clear();
    equipmentIcon.clear();

    Mat infoImg;
    try {
        Point matchLocation = CVA::matchTemplate(srcImg, templateImg);
        Rect selectInfo = Rect(matchLocation.x - matchIconPosX, matchLocation.y - matchIconPosY, userInfoWidth, userInfoHeight);
        infoImg = srcImg(selectInfo);
    } catch (cv::Exception &e) {
        qWarning() << "Failed to find userinfo. " << e.what();
        mainTray->showMessage(QString::fromLocal8Bit("分析失败"), //消息窗口标题
                              QString::fromLocal8Bit("检测不到角色面板"), //消息内容
                              QSystemTrayIcon::MessageIcon::Warning, //消息窗口图标
                              1000); //消息窗口显示时长
        this->mode = false;
        this->close();
        return;
    }

    saveImg = infoImg.clone();
    QtConcurrent::run([this]() {
        QPixmap tmpQPm = CVA::cvMatToQPixmap(saveImg);
        tmpQPm.save("./log/info.png");
    });
    Mat classImg;
    try {
        Rect selectClass = Rect(classPosX, classPosY, classWidth, classHeight);
        classImg = infoImg(selectClass);
        for (int i = 0; i < classImg.rows; ++i) {
            uchar *data = classImg.ptr<uchar>(i);
            for (int j = 0; j < classImg.cols * 3; j += 3) {
                if (data[j] < 220 || data[j + 1] < 220 || data[j + 2] < 220) {
                    data[j] = data[j + 1] = data[j + 2] = 0;
                } else {
                    data[j] = data[j + 1] = data[j + 2] = 255;
                }
            }
        }
        QtConcurrent::run([&classImg]() {
            QPixmap tmpQPm = CVA::cvMatToQPixmap(classImg);
            tmpQPm.save("./log/classname.png");
        });
    } catch (cv::Exception &e) {
        qWarning() << "Failed to select or binarize classname. " << e.what();
        mainTray->showMessage(QString::fromLocal8Bit("分析失败"), //消息窗口标题
                              QString::fromLocal8Bit("检测职业时出现错误"), //消息内容
                              QSystemTrayIcon::MessageIcon::Warning, //消息窗口图标
                              1000); //消息窗口显示时长
        this->mode = false;
        this->close();
        return;
    }

    try {
        int _y = 0;
        double score = 0;
        for (int i = 0; i < 61; ++i) {
            Mat m_name = classNameImg(Rect(0, _y, 96, 14)), m_oldname = classNameImg(Rect(96, _y, 96, 14));
            Point p = CVA::matchTemplate(classImg, m_name), oldp = CVA::matchTemplate(classImg, m_oldname);
            double tmpscore = CVA::getPSNR(classImg(Rect(p.x, p.y, 96, 14)), m_name);
            if (tmpscore > score) {
                score = tmpscore;
                classID = i;
                className = classVec[i].name;
            }
            tmpscore = CVA::getPSNR(classImg(Rect(oldp.x, oldp.y, 96, 14)), m_oldname);
            if (tmpscore > score) {
                score = tmpscore;
                classID = i;
                className = classVec[i].oldname;
            }
            _y += 14;
        }
    } catch (cv::Exception &e) {
        qWarning() << "Failed to match classname. Check 'classname.png'. " << e.what();
        mainTray->showMessage(QString::fromLocal8Bit("分析失败"), //消息窗口标题
                              QString::fromLocal8Bit("检测职业时出现错误"), //消息内容
                              QSystemTrayIcon::MessageIcon::Warning, //消息窗口图标
                              1000); //消息窗口显示时长
        this->mode = false;
        this->close();
        return;
    }

    double score = 0.0;
    try {
        Point p = CVA::matchTemplate(infoImg, buffBookImg);
        score = CVA::getPSNR(infoImg(Rect(p.x, p.y, 16, 18)), buffBookImg);
        score /= (1 + (p.x - 35) * (p.x - 35));
        score /= (1 + (p.y - 187) * (p.y - 187));
    } catch (cv::Exception &e) {
        qWarning() << "Failed to match buffbook. Check 'info.png'. " << e.what();
        mainTray->showMessage(QString::fromLocal8Bit("分析失败"), //消息窗口标题
                              QString::fromLocal8Bit("判断是否为他人面板时出现错误"), //消息内容
                              QSystemTrayIcon::MessageIcon::Warning, //消息窗口图标
                              1000); //消息窗口显示时长
        this->mode = false;
        this->close();
        return;
    }

    qDebug() << "PSNR score: " << score;
    QVector<LayoutData> *layout;
    if (score > PSNRthreshold) layout = &otherVec;
    else layout = &selfVec;

    equipmentInfoVec[5] = weaponInfoVec[classVec[classID].weaponType];
    equipmentImgVec[5] = weaponImgVec[classVec[classID].weaponType];

    QString infoString;
    QTextStream qts(&infoString);

    for (LayoutData data : *layout) {
        if (data.id < 13) {
            Point mp;
            try {
                mp = CVA::matchTemplate(equipmentImgVec[data.id], infoImg(data.getSelect()));
            } catch (cv::Exception &e) {
                qWarning() << "Failed to detect equipment named " << data.name.toStdString().c_str() << ". Check 'info.png'. " << e.what();
                mainTray->showMessage(QString::fromLocal8Bit("分析失败"), //消息窗口标题
                                      QString::fromLocal8Bit("检测装备时出现错误"), //消息内容
                                      QSystemTrayIcon::MessageIcon::Warning, //消息窗口图标
                                      1000); //消息窗口显示时长
                this->mode = false;
                this->close();
                return;
            }
            int index = mp.y / iconHeight;
            qts << data.name << QString::fromLocal8Bit("：") << equipmentInfoVec[data.id][index].name << endl;
            qs.insert(equipmentInfoVec[data.id][index].name);
            Mat m_tmp = equipmentImgVec[data.id](Rect(1, iconHeight * index + 1, iconWidth - 2, iconHeight - 2));
            if (data.id != 5) {
                setCnt[equipmentInfoVec[data.id][index].setid]++;
                equipmentIcon.insert(data.name, std::make_pair(m_tmp, equipmentInfoVec[data.id][index].setid));
            } else {
                wType = equipmentInfoVec[data.id][index].setid;
                equipmentIcon.insert(data.name, std::make_pair(m_tmp, 0));
            }
        } else {
            Mat tmpMat;
            try {
                tmpMat = infoImg(data.getSelect());
            } catch (cv::Exception &e) {
                //QMessageBox::critical(NULL, "分析失败", "检测属性时出现错误");
                qWarning() << "Failed to select attribute named " << data.name.toStdString().c_str() << ". Check 'info.png'. " << e.what();
                mainTray->showMessage(QString::fromLocal8Bit("分析失败"), //消息窗口标题
                                      QString::fromLocal8Bit("检测属性时出现错误"), //消息内容
                                      QSystemTrayIcon::MessageIcon::Warning, //消息窗口图标
                                      1000); //消息窗口显示时长
                this->mode = false;
                this->close();
                return;
            }
            for (int i = 0; i < tmpMat.rows; ++i) {
                uchar *data = tmpMat.ptr<uchar>(i);
                for (int j = 0; j < tmpMat.cols * 3; j += 3) {
                    if (int(data[j]) + int(data[j + 1]) + int(data[j + 2]) > 180) {
                        data[j] = data[j + 1] = data[j + 2] = 255;
                    } else {
                        data[j] = data[j + 1] = data[j + 2] = 0;
                    }
                }
            }
            QtConcurrent::run([&tmpMat, &data]() {
                QPixmap tmpQPm = CVA::cvMatToQPixmap(tmpMat);
                tmpQPm.save("./log/" + QString::number(data.id) + ".png");
            });
            QString ss = "";
            try {
                Mat gray;
                cvtColor(tmpMat, gray, CV_BGR2GRAY);
                Mat thre;
                threshold(gray, thre, 127, 255, THRESH_BINARY);
                vector<vector<Point> > contours;
                vector<Vec4i> hierarchy;
                findContours(thre, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point());
                QVector<pair<int, QString>> resVec;
                for (auto c : contours) {
                    Rect r = boundingRect(c);
                    Point mp = CVA::matchTemplate(charImg, tmpMat(Rect(r.x - 1, r.y - 1, r.width + 2, r.height + 2)));
                    resVec.push_back(make_pair(r.x, charVec[mp.x / charWidth].name));
                }
                sort(resVec.begin(), resVec.end());
                qts << data.name << QString::fromLocal8Bit("：");
                for (pair<int, QString> v : resVec)
                    ss = ss + v.second;
            } catch (cv::Exception &e) {
                //QMessageBox::critical(NULL, "分析失败", "检测属性时出现错误");
                qWarning() << "Failed to detect attribute named " << data.name.toStdString().c_str()
                           << ". Check '" + QString::number(data.id) + ".png'. " << e.what();
                mainTray->showMessage(QString::fromLocal8Bit("分析失败"), //消息窗口标题
                                      QString::fromLocal8Bit("检测属性时出现错误"), //消息内容
                                      QSystemTrayIcon::MessageIcon::Warning, //消息窗口图标
                                      1000); //消息窗口显示时长
                this->mode = false;
                this->close();
                return;
            }
            qts << ss << endl;
            if (data.id == 13) STR = ss.toInt();
            else if (data.id == 14) INT = ss.toInt();
            else if (data.id == 15) P_ATK = ss.toInt();
            else if (data.id == 16) M_ATK = ss.toInt();
            else if (data.id == 17) I_ATK = ss.toInt();
            else if (data.id == 18) P_CRT = ss.toDouble();
            else if (data.id == 19) M_CRT = ss.toDouble();
            else if (data.id == 20) {
                QStringList li = ss.split("/");
                FIRE = li.value(0, "0").toInt();
                ICE = li.value(1, "0").toInt();
                LIGHT = li.value(2, "0").toInt();
                DARK = li.value(3, "0").toInt();
                ELE = std::max(FIRE, std::max(ICE, std::max(LIGHT, DARK)));
            }
        }
    }

    qDebug() << "user info detected";
//qDebug() << STR << " " << INT << " " << P_ATK << " " << M_ATK << " " << I_ATK << " " << P_CRT << " " << M_CRT << endl;

    decideFlags(classVec[classID], isPhy, isInd, aType);
    collectAttr(attr, atk, crt);

    ui->characterLbl->installEventFilter(this);
    ui->pantsIcon->installEventFilter(this);
    ui->ringIcon->installEventFilter(this);
    ui->supportIcon->installEventFilter(this);

    bool siroco = false, switchclass = false, switchtype = false;

    if (qs.contains(QString::fromLocal8Bit("无形：奈克斯的灵魂仪服")) || qs.contains(QString::fromLocal8Bit("无形：暗杀者的灵魂残念")) || qs.contains(QString::fromLocal8Bit("无形：卢克西的灵魂狂气"))
            || qs.contains(QString::fromLocal8Bit("无形：守门人的灵魂甲胄")) || qs.contains(QString::fromLocal8Bit("无形：洛多斯的灵魂意志"))) {
        siroco = true;
        pantsMenu = new QMenu(this);
        pantsid = -1;
        pantsVec.clear();
        for (EquipmentData v : equipmentInfoVec[2]) {
            if (v.id > 27) continue;
            if (v.id >= 20 && v.id <= 27 && setCnt.at(v.setid) != 4) continue;
            if (v.id <= 19 && (setCnt.at(v.setid) == 0 || setCnt.at(v.setid) == 3 || setCnt.at(v.setid) >= 5)) continue;
            if (setCnt.at(v.setid) == 4) pantsid = pantsVec.size();
            pantsVec.push_back(v.id);
            QAction *tmpAction = new QAction(this);
            pantsMenu->addAction(tmpAction);
        }
        if (pantsid == -1) {
            pantsVec.push_back(28);
            QAction *tmpAction = new QAction(this);
            pantsMenu->addAction(tmpAction);
            pantsid = 0;
        }
        auto setActions = [ = ]() {
            for (int i = 0; i < pantsVec.size(); ++i) {
                int setid = equipmentInfoVec[2].at(pantsVec.at(i)).setid;
                if (setid > 0)
                    pantsMenu->actions().at(i)->setText(setVec.at(setid - 1).name + "-" + equipmentInfoVec[2].at(pantsVec.at(i)).name);
                else
                    pantsMenu->actions().at(i)->setText(equipmentInfoVec[2].at(pantsVec.at(i)).name);
            }
            pantsMenu->actions().at(pantsid)->setText(pantsMenu->actions().at(pantsid)->text() + QString::fromLocal8Bit(" √"));
        };
        setCnt[equipmentInfoVec[2].at(pantsVec.at(pantsid)).setid]++;
        qs.insert(equipmentInfoVec[2].at(pantsVec.at(pantsid)).name);
        setActions();
        for (int i = 0; i < pantsVec.size(); ++i)
            connect(pantsMenu->actions().at(i), &QAction::triggered, [ = ]() {
            setCnt[equipmentInfoVec[2].at(pantsVec.at(pantsid)).setid]--;
            qs.remove(equipmentInfoVec[2].at(pantsVec.at(pantsid)).name);
            pantsid = i;
            setCnt[equipmentInfoVec[2].at(pantsVec.at(pantsid)).setid]++;
            qs.insert(equipmentInfoVec[2].at(pantsVec.at(pantsid)).name);
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
    }

    if (qs.contains(QString::fromLocal8Bit("无欲：奈克斯的梦幻黑暗")) || qs.contains(QString::fromLocal8Bit("无欲：暗杀者的梦幻痕迹")) || qs.contains(QString::fromLocal8Bit("无欲：卢克西的梦幻约定"))
            || qs.contains(QString::fromLocal8Bit("无欲：守门人的梦幻邪念")) || qs.contains(QString::fromLocal8Bit("无欲：洛多斯的梦幻根源"))) {
        siroco = true;
        ringMenu = new QMenu(this);
        ringid = 0;
        ringVec.clear();
        for (EquipmentData v : equipmentInfoVec[10]) {
            if (v.id > 11) continue;
            if (v.id >= 9 && v.id <= 11 && setCnt.at(v.setid) != 2) continue;
            if (v.id <= 8 && (setCnt.at(v.setid) == 0 || setCnt.at(v.setid) >= 3)) continue;
            if (v.id >= 9 && v.id <= 11 && setCnt.at(v.setid) == 2) ringid = ringVec.size();
            ringVec.push_back(v.id);
            QAction *tmpAction = new QAction(this);
            ringMenu->addAction(tmpAction);
        }
        {
            ringVec.push_back(12);
            QAction *tmpAction = new QAction(this);
            ringMenu->addAction(tmpAction);
        }
        auto setActions = [ = ]() {
            for (int i = 0; i < ringVec.size(); ++i) {
                int setid = equipmentInfoVec[10].at(ringVec.at(i)).setid;
                if (setid > 0)
                    ringMenu->actions().at(i)->setText(setVec.at(setid - 1).name + "-" + equipmentInfoVec[10].at(ringVec.at(i)).name);
                else
                    ringMenu->actions().at(i)->setText(equipmentInfoVec[10].at(ringVec.at(i)).name);
            }
            ringMenu->actions().at(ringid)->setText(ringMenu->actions().at(ringid)->text() + QString::fromLocal8Bit(" √"));
        };
        setCnt[equipmentInfoVec[10].at(ringVec.at(ringid)).setid]++;
        qs.insert(equipmentInfoVec[10].at(ringVec.at(ringid)).name);
        setActions();
        for (int i = 0; i < ringVec.size(); ++i)
            connect(ringMenu->actions().at(i), &QAction::triggered, [ = ]() {
            setCnt[equipmentInfoVec[10].at(ringVec.at(ringid)).setid]--;
            qs.remove(equipmentInfoVec[10].at(ringVec.at(ringid)).name);
            ringid = i;
            setCnt[equipmentInfoVec[10].at(ringVec.at(ringid)).setid]++;
            qs.insert(equipmentInfoVec[10].at(ringVec.at(ringid)).name);
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
    }

    if (qs.contains(QString::fromLocal8Bit("幻影：奈克斯的黑色之息")) || qs.contains(QString::fromLocal8Bit("幻影：暗杀者的黑色剑鞘")) || qs.contains(QString::fromLocal8Bit("幻影：卢克西的黑色鬼神缚"))
            || qs.contains(QString::fromLocal8Bit("幻影：守门人的黑色面具")) || qs.contains(QString::fromLocal8Bit("幻影：洛多斯的黑色核心"))) {
        siroco = true;
        supportMenu = new QMenu(this);
        supportid = 0;
        supportVec.clear();
        for (EquipmentData v : equipmentInfoVec[9]) {
            if (v.id > 9) continue;
            if (v.id == 9 && setCnt.at(v.setid) != 2) continue;
            if (v.id <= 8 && (setCnt.at(v.setid) == 0 || setCnt.at(v.setid) >= 3)) continue;
            if (v.id == 9 && setCnt.at(v.setid) == 2) supportid = supportVec.size();
            supportVec.push_back(v.id);
            QAction *tmpAction = new QAction(this);
            supportMenu->addAction(tmpAction);
        }
        {
            supportVec.push_back(10);
            QAction *tmpAction = new QAction(this);
            supportMenu->addAction(tmpAction);
        }
        if (setCnt.at(45) == 5) {
            supportid = supportVec.size();
            supportVec.push_back(11);
            QAction *tmpAction = new QAction(this);
            supportMenu->addAction(tmpAction);
        }
        if (setCnt.at(43) == 5) {
            supportid = supportVec.size();
            supportVec.push_back(12);
            QAction *tmpAction = new QAction(this);
            supportMenu->addAction(tmpAction);
        }
        if (setCnt.at(42) == 5) {
            supportid = supportVec.size();
            supportVec.push_back(13);
            QAction *tmpAction = new QAction(this);
            supportMenu->addAction(tmpAction);
        }
        auto setActions = [ = ]() {
            for (int i = 0; i < supportVec.size(); ++i) {
                int setid = equipmentInfoVec[9].at(supportVec.at(i)).setid;
                if (setid > 0)
                    supportMenu->actions().at(i)->setText(setVec.at(setid - 1).name + "-" + equipmentInfoVec[9].at(supportVec.at(i)).name);
                else
                    supportMenu->actions().at(i)->setText(equipmentInfoVec[9].at(supportVec.at(i)).name);
            }
            supportMenu->actions().at(supportid)->setText(supportMenu->actions().at(supportid)->text() + QString::fromLocal8Bit(" √"));
        };
        setCnt[equipmentInfoVec[9].at(supportVec.at(supportid)).setid]++;
        qs.insert(equipmentInfoVec[9].at(supportVec.at(supportid)).name);
        setActions();
        for (int i = 0; i < supportVec.size(); ++i)
            connect(supportMenu->actions().at(i), &QAction::triggered, [ = ]() {
            setCnt[equipmentInfoVec[9].at(supportVec.at(supportid)).setid]--;
            qs.remove(equipmentInfoVec[9].at(supportVec.at(supportid)).name);
            supportid = i;
            setCnt[equipmentInfoVec[9].at(supportVec.at(supportid)).setid]++;
            qs.insert(equipmentInfoVec[9].at(supportVec.at(supportid)).name);
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
    }

    if (className == classVec[9].name) {
        switchclass = true;
        classMenu = new QMenu(this);
        QAction *tmpAction1 = new QAction(this);
        QAction *tmpAction2 = new QAction(this);
        classMenu->addAction(tmpAction1);
        classMenu->addAction(tmpAction2);
        auto setActions = [ = ]() {
            tmpAction1->setText(QString::fromLocal8Bit("男气功"));
            tmpAction2->setText(QString::fromLocal8Bit("女气功"));
            if (classID == 9) {
                tmpAction1->setText(tmpAction1->text() + QString::fromLocal8Bit(" √"));
            } else {
                tmpAction2->setText(tmpAction2->text() + QString::fromLocal8Bit(" √"));
            }
        };
        setActions();
        connect(tmpAction1, &QAction::triggered, [ = ]() {
            classID = 9;
            decideFlags(classVec[classID], isPhy, isInd, aType);
            collectAttr(attr, atk, crt);
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction2, &QAction::triggered, [ = ]() {
            classID = 13;
            decideFlags(classVec[classID], isPhy, isInd, aType);
            collectAttr(attr, atk, crt);
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
    }

    if (className == classVec[10].name) {
        switchclass = true;
        classMenu = new QMenu(this);
        QAction *tmpAction1 = new QAction(this);
        QAction *tmpAction2 = new QAction(this);
        classMenu->addAction(tmpAction1);
        classMenu->addAction(tmpAction2);
        auto setActions = [ = ]() {
            tmpAction1->setText(QString::fromLocal8Bit("男武极"));
            tmpAction2->setText(QString::fromLocal8Bit("女武神"));
            if (classID == 10) {
                tmpAction1->setText(tmpAction1->text() + QString::fromLocal8Bit(" √"));
            } else {
                tmpAction2->setText(tmpAction2->text() + QString::fromLocal8Bit(" √"));
            }
        };
        setActions();
        connect(tmpAction1, &QAction::triggered, [ = ]() {
            classID = 10;
            decideFlags(classVec[classID], isPhy, isInd, aType);
            collectAttr(attr, atk, crt);
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction2, &QAction::triggered, [ = ]() {
            classID = 14;
            decideFlags(classVec[classID], isPhy, isInd, aType);
            collectAttr(attr, atk, crt);
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
    }

    if (className == classVec[11].name) {
        switchclass = true;
        classMenu = new QMenu(this);
        QAction *tmpAction1 = new QAction(this);
        QAction *tmpAction2 = new QAction(this);
        QAction *tmpAction3 = new QAction(this);
        QAction *tmpAction4 = new QAction(this);
        classMenu->addAction(tmpAction1);
        classMenu->addAction(tmpAction2);
        classMenu->addAction(tmpAction3);
        classMenu->addAction(tmpAction4);
        auto setActions = [ = ]() {
            tmpAction1->setText(QString::fromLocal8Bit("物理男街霸"));
            tmpAction2->setText(QString::fromLocal8Bit("魔法男街霸"));
            tmpAction3->setText(QString::fromLocal8Bit("物理女毒王"));
            tmpAction4->setText(QString::fromLocal8Bit("魔法女毒王"));
            if (classID == 11) {
                if (isPhy) tmpAction1->setText(tmpAction1->text() + QString::fromLocal8Bit(" √"));
                else tmpAction2->setText(tmpAction2->text() + QString::fromLocal8Bit(" √"));
            } else {
                if (isPhy) tmpAction3->setText(tmpAction3->text() + QString::fromLocal8Bit(" √"));
                else tmpAction4->setText(tmpAction4->text() + QString::fromLocal8Bit(" √"));
            }
        };
        setActions();
        connect(tmpAction1, &QAction::triggered, [ = ]() {
            classID = 11;
            decideFlags(classVec[classID], isPhy, isInd, aType);
            isPhy = true;
            collectAttr(attr, atk, crt);
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction2, &QAction::triggered, [ = ]() {
            classID = 11;
            decideFlags(classVec[classID], isPhy, isInd, aType);
            isPhy = false;
            collectAttr(attr, atk, crt);
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction3, &QAction::triggered, [ = ]() {
            classID = 15;
            decideFlags(classVec[classID], isPhy, isInd, aType);
            isPhy = true;
            collectAttr(attr, atk, crt);
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction4, &QAction::triggered, [ = ]() {
            classID = 15;
            decideFlags(classVec[classID], isPhy, isInd, aType);
            isPhy = false;
            collectAttr(attr, atk, crt);
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
    }

    if (className == classVec[12].name) {
        switchclass = true;
        classMenu = new QMenu(this);
        QAction *tmpAction1 = new QAction(this);
        QAction *tmpAction2 = new QAction(this);
        classMenu->addAction(tmpAction1);
        classMenu->addAction(tmpAction2);
        auto setActions = [ = ]() {
            tmpAction1->setText(QString::fromLocal8Bit("男柔道"));
            tmpAction2->setText(QString::fromLocal8Bit("女柔道"));
            if (classID == 12) {
                tmpAction1->setText(tmpAction1->text() + QString::fromLocal8Bit(" √"));
            } else {
                tmpAction2->setText(tmpAction2->text() + QString::fromLocal8Bit(" √"));
            }
        };
        setActions();
        connect(tmpAction1, &QAction::triggered, [ = ]() {
            classID = 12;
            decideFlags(classVec[classID], isPhy, isInd, aType);
            collectAttr(attr, atk, crt);
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction2, &QAction::triggered, [ = ]() {
            classID = 16;
            decideFlags(classVec[classID], isPhy, isInd, aType);
            collectAttr(attr, atk, crt);
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
    }

    if (classID == 20 || classID == 24 || classID == 32 || className == classVec[11].oldname || className == classVec[15].oldname) {
        switchtype = true;
        classMenu = new QMenu(this);
        QAction *tmpAction1 = new QAction(this);
        QAction *tmpAction2 = new QAction(this);
        classMenu->addAction(tmpAction1);
        classMenu->addAction(tmpAction2);
        auto setActions = [ = ]() {
            tmpAction1->setText(QString::fromLocal8Bit("物理"));
            tmpAction2->setText(QString::fromLocal8Bit("魔法"));
            if (isPhy) {
                tmpAction1->setText(tmpAction1->text() + QString::fromLocal8Bit(" √"));
            } else {
                tmpAction2->setText(tmpAction2->text() + QString::fromLocal8Bit(" √"));
            }
        };
        setActions();
        connect(tmpAction1, &QAction::triggered, [ = ]() {
            isPhy = true;
            collectAttr(attr, atk, crt);
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction2, &QAction::triggered, [ = ]() {
            isPhy = false;
            collectAttr(attr, atk, crt);
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
    }

    if (classID == 37) {
        switchtype = true;
        classMenu = new QMenu(this);
        QAction *tmpAction1 = new QAction(this);
        QAction *tmpAction2 = new QAction(this);
        QAction *tmpAction3 = new QAction(this);
        classMenu->addAction(tmpAction1);
        classMenu->addAction(tmpAction2);
        classMenu->addAction(tmpAction3);
        auto setActions = [ = ]() {
            tmpAction1->setText(QString::fromLocal8Bit("魔法布甲"));
            tmpAction2->setText(QString::fromLocal8Bit("物理重甲"));
            tmpAction3->setText(QString::fromLocal8Bit("物理板甲"));
        };
        setActions();
        if (isPhy) {
            tmpAction2->setText(tmpAction2->text() + QString::fromLocal8Bit(" √"));
        } else {
            tmpAction1->setText(tmpAction1->text() + QString::fromLocal8Bit(" √"));
        }
        connect(tmpAction1, &QAction::triggered, [ = ]() {
            isPhy = false;
            aType = 1;
            collectAttr(attr, atk, crt);
            setActions();
            tmpAction1->setText(tmpAction1->text() + QString::fromLocal8Bit(" √"));
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction2, &QAction::triggered, [ = ]() {
            isPhy = true;
            aType = 4;
            collectAttr(attr, atk, crt);
            setActions();
            tmpAction2->setText(tmpAction2->text() + QString::fromLocal8Bit(" √"));
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction3, &QAction::triggered, [ = ]() {
            isPhy = true;
            aType = 5;
            collectAttr(attr, atk, crt);
            setActions();
            tmpAction3->setText(tmpAction3->text() + QString::fromLocal8Bit(" √"));
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
    }

    if (classID == 60) {
        switchtype = true;
        classMenu = new QMenu(this);
        QAction *tmpAction1 = new QAction(this);
        QAction *tmpAction2 = new QAction(this);
        QAction *tmpAction3 = new QAction(this);
        QAction *tmpAction4 = new QAction(this);
        classMenu->addAction(tmpAction1);
        classMenu->addAction(tmpAction2);
        classMenu->addAction(tmpAction3);
        classMenu->addAction(tmpAction4);
        auto setActions = [ = ]() {
            tmpAction1->setText(QString::fromLocal8Bit("魔法布甲"));
            tmpAction2->setText(QString::fromLocal8Bit("物理轻甲"));
            tmpAction3->setText(QString::fromLocal8Bit("物理重甲"));
            tmpAction4->setText(QString::fromLocal8Bit("魔法板甲"));
        };
        setActions();
        if (isPhy) {
            tmpAction2->setText(tmpAction2->text() + QString::fromLocal8Bit(" √"));
        } else {
            tmpAction1->setText(tmpAction1->text() + QString::fromLocal8Bit(" √"));
        }
        connect(tmpAction1, &QAction::triggered, [ = ]() {
            isPhy = false;
            aType = 1;
            collectAttr(attr, atk, crt);
            setActions();
            tmpAction1->setText(tmpAction1->text() + QString::fromLocal8Bit(" √"));
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction2, &QAction::triggered, [ = ]() {
            isPhy = true;
            aType = 3;
            collectAttr(attr, atk, crt);
            setActions();
            tmpAction2->setText(tmpAction2->text() + QString::fromLocal8Bit(" √"));
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction3, &QAction::triggered, [ = ]() {
            isPhy = true;
            aType = 4;
            collectAttr(attr, atk, crt);
            setActions();
            tmpAction3->setText(tmpAction3->text() + QString::fromLocal8Bit(" √"));
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction4, &QAction::triggered, [ = ]() {
            isPhy = false;
            aType = 5;
            collectAttr(attr, atk, crt);
            setActions();
            tmpAction4->setText(tmpAction4->text() + QString::fromLocal8Bit(" √"));
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
    }

    Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
    refresh(model);

    qInfo() << "UserinfoWindow sucessfully loaded.";

    this->show();

    QString messageText;

    if (SettingData::setflag("result")) {
        messageText += QString::fromLocal8Bit("<p>这是您首次打开结果窗口，点击<a href=\"https://quack8102.gitee.io/#/resultwindow\">这里</a>打开说明页面。</p>");
    }

    if (switchclass) {
        if (SettingData::setflag("switchclass")) {
            messageText += QString::fromLocal8Bit("<p>这是您首次检测到可以切换的同名职业，点击<a href=\"https://quack8102.gitee.io/#/resultwindow?id=switchclass\">这里</a>打开说明页面。</p>");
        }
    }

    if (siroco) {
        if (SettingData::setflag("siroco")) {
            messageText += QString::fromLocal8Bit("<p>这是您首次检测到希洛克装备，点击<a href=\"https://quack8102.gitee.io/#/resultwindow?id=siroco\">这里</a>打开说明页面。</p>");
        }
    }

    if (switchtype) {
        if (SettingData::setflag("switchtype")) {
            messageText += QString::fromLocal8Bit("<p>这是您首次检测到可以切换物理魔法或防具精通的职业，点击<a href=\"https://quack8102.gitee.io/#/resultwindow?id=switchtype\">这里</a>打开说明页面。</p>");
        }
    }

    if (!messageText.isEmpty()) {
        SettingData::sendMessage(messageText);
    }
}

bool UserInfoWindow::eventFilter(QObject *obj, QEvent *event) {
    if (qobject_cast<QLabel *>(obj) == ui->characterLbl && event->type() == QEvent::MouseButtonRelease) {
        if (classMenu != NULL) {
            QMouseEvent *e = static_cast<QMouseEvent *>(event);
            classMenu->exec(e->globalPos());
        }
        return true;
    } else if (qobject_cast<QLabel *>(obj) == ui->pantsIcon && event->type() == QEvent::MouseButtonRelease) {
        if (pantsMenu != NULL) {
            QMouseEvent *e = static_cast<QMouseEvent *>(event);
            pantsMenu->exec(e->globalPos());
        }
        return true;
    } else if (qobject_cast<QLabel *>(obj) == ui->ringIcon && event->type() == QEvent::MouseButtonRelease) {
        if (ringMenu != NULL) {
            QMouseEvent *e = static_cast<QMouseEvent *>(event);
            ringMenu->exec(e->globalPos());
        }
        return true;
    } else if (qobject_cast<QLabel *>(obj) == ui->supportIcon && event->type() == QEvent::MouseButtonRelease) {
        if (supportMenu != NULL) {
            QMouseEvent *e = static_cast<QMouseEvent *>(event);
            supportMenu->exec(e->globalPos());
        }
        return true;
    } else {
        return false;
        //return QMainWindow::eventFilter(obj, event);
    }
}

void UserInfoWindow::closeEvent(QCloseEvent *event) {
    if (SettingData::isAutoSave && this->mode) {
        QDateTime current_date_time = QDateTime::currentDateTime();
        QString suffix = current_date_time.toString("yyyy_MMdd_hhmmsszzz");
        QDir dir;
        if (!dir.exists("save")) {
            QDir dir;
            dir.mkdir("save");
        }
        if (!dir.exists("./save/" + suffix)) {
            if (dir.mkpath("./save/" + suffix)) {
                QPixmap sqpm = CVA::cvMatToQPixmap(saveImg);
                sqpm.save("./save/" + suffix + "/character_" + suffix + ".png");
                QFile file("./save/" + suffix + "/result_" + suffix + ".json");
                if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    qCritical() << "Failed to save json file.";
                    mainTray->showMessage(QString::fromLocal8Bit("保存失败"), //消息窗口标题
                                          QString::fromLocal8Bit("文件打开失败"), //消息内容
                                          QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                                          1000); //消息窗口显示时长
                } else {
                    QJsonDocument qjd(outQJO);
                    QByteArray qba = qjd.toJson();
                    file.write(qba);
                    file.close();
                }
            } else {
                qCritical() << "Failed to create dir named " << suffix << ".";
                mainTray->showMessage(QString::fromLocal8Bit("保存失败"), //消息窗口标题
                                      QString::fromLocal8Bit("创建文件夹时出现错误"), //消息内容
                                      QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                                      1000); //消息窗口显示时长
            }
        }
    }
}

void UserInfoWindow::decideFlags(const ClassData &cd, bool &isPhy, bool &isInd, int &armorType) {
    if (cd.PHY == 0) {
        if (cd.IND == 1) isPhy = STR > INT;
        else isPhy = P_ATK > M_ATK;
    } else {
        isPhy = (cd.PHY == 1);
    }
    isInd = (cd.IND == 1);
    armorType = cd.type;
    if (armorType == 0) {
        if (cd.id == 37) armorType = isPhy ? 4 : 1;
        else if (cd.id == 60) armorType = isPhy ? 3 : 1;
    }
}

void UserInfoWindow::collectAttr(int &attr, int &atk, double &crt) {
    if (isPhy) attr = STR, crt = P_CRT;
    else attr = INT, crt = M_CRT;
    if (isInd) atk = I_ATK;
    else {
        if (isPhy) atk = P_ATK;
        else atk = M_ATK;
    }
}

void UserInfoWindow::refresh(Character &model) {
    qDebug() << "Trying to calculate the model.";
    for (AttrData ad : SettingData::vec) {
        ad(model);
    }
    for (QString en : qs) {
        auto p = Factory<Equipment>::Instance().get(en);
        if (p == NULL) {
            qCritical() << "Failed to find equipment named" << en.toStdString().c_str() << ".";
            mainTray->showMessage(QString::fromLocal8Bit("分析失败"), //消息窗口标题
                                  QString::fromLocal8Bit("计算装备属性时出现错误"), //消息内容
                                  QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                                  1000); //消息窗口显示时长
            this->mode = false;
            this->close();
            return;
        }
        (*p)(model);
    }
    for (SetData sd : setVec) {
        auto p = Factory<Equipment>::Instance().get(sd.name);
        if (p == NULL) {
            qCritical() << "Failed to find set named" << sd.name.toStdString().c_str() << ".";
            mainTray->showMessage(QString::fromLocal8Bit("分析失败"), //消息窗口标题
                                  QString::fromLocal8Bit("计算套装属性时出现错误"), //消息内容
                                  QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                                  1000); //消息窗口显示时长
            this->mode = false;
            this->close();
            return;
        }
        (*p)(model);
    }
    //model.showDetail();
    {
        QString qstr = QString::number(model.classID);
        //qDebug() << qstr << endl;
        auto p = Factory<Equipment>::Instance().get(qstr);
        if (p != NULL) (*p)(model);
        else {
            qCritical() << "Failed to find class indexed" << model.classID << ".";
            mainTray->showMessage(QString::fromLocal8Bit("分析失败"), //消息窗口标题
                                  QString::fromLocal8Bit("计算职业属性时出现错误"), //消息内容
                                  QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                                  1000); //消息窗口显示时长
            this->mode = false;
            this->close();
            return;
        }
    }
    //model.showDetail();
    QString qstr;
    QTextStream stream(&qstr);
    stream << QString::fromLocal8Bit("人物主属性：") << attr << QString::fromLocal8Bit("，模板主属性：") << int(model.attr) << endl;
    stream << QString::fromLocal8Bit("人物攻击力：") << atk << QString::fromLocal8Bit("，模板攻击力：");
    if (model.isInd) {
        stream << int(model.atk) << endl;
    } else {
        stream << int(model.atk * (1 + int(model.attr) / 250.0)) << endl;
    }
    stream << QString::fromLocal8Bit("人物进图暴击率：") << model.minCrt << QString::fromLocal8Bit("% ~ ") << model.maxCrt << QString::fromLocal8Bit("%") << endl;
    stream << QString::fromLocal8Bit("模特属强：") << std::max(model.FIRE_OUT, std::max(model.ICE_OUT, std::max(model.LIGHT_OUT, model.DARK_OUT))) << endl;
    stream << QString::fromLocal8Bit("人物词条数：") << model.entryCnt << QString::fromLocal8Bit("，智慧产物数：") << model.reformCnt << endl;
    //ui->infoLbl->setText(qstr);

    //ui->classLbl->setText("职业： " + classVec[classID].name);
    //if (classVec[classID].synergy == 1) ui->synergyLbl->setText("协同C");
    //else if (classVec[classID].synergy == -1) ui->synergyLbl->setText("纯C");
    //else ui->synergyLbl->setText("可切换");

    QFont font("simsun");
    font.setPixelSize(12);
    ui->entryCntInfo->setFont(font);
    ui->entryCntLbl->setFont(font);
    ui->maxCrtInfo->setFont(font);
    ui->maxCrtLbl->setFont(font);
    ui->minCrtInfo->setFont(font);
    ui->minCrtLbl->setFont(font);
    ui->modelAtkInfo->setFont(font);
    ui->modelAtkLbl->setFont(font);
    ui->modelAttrInfo->setFont(font);
    ui->modelAttrLbl->setFont(font);
    ui->modelElementInfo->setFont(font);
    ui->modelElementLbl->setFont(font);
    ui->reformCntInfo->setFont(font);
    ui->reformCntLbl->setFont(font);
    ui->selfAtkInfo->setFont(font);
    ui->selfAtkLbl->setFont(font);
    ui->selfAttrInfo->setFont(font);
    ui->selfAttrLbl->setFont(font);
    ui->selfElementInfo->setFont(font);
    ui->selfElementLbl->setFont(font);

    QFont bigFont("simsun");
    bigFont.setBold(true);
    bigFont.setPixelSize(25);
    ui->resultLbl->setFont(bigFont);

    try {
        updateIcon(QString::fromLocal8Bit("腰带"), ui->beltIcon, model);
        updateIcon(QString::fromLocal8Bit("手镯"), ui->braceletIcon, model);
        updateIcon(QString::fromLocal8Bit("上衣"), ui->coatIcon, model);
        updateIcon(QString::fromLocal8Bit("耳环"), ui->earringIcon, model);
        updateIcon(QString::fromLocal8Bit("右槽"), ui->magicstoneIcon, model);
        updateIcon(QString::fromLocal8Bit("肩"), ui->neckIcon, model);
        updateIcon(QString::fromLocal8Bit("项链"), ui->necklaceIcon, model);
        updateIcon(QString::fromLocal8Bit("裤子"), ui->pantsIcon, model);
        updateIcon(QString::fromLocal8Bit("戒指"), ui->ringIcon, model);
        updateIcon(QString::fromLocal8Bit("鞋子"), ui->shoesIcon, model);
        updateIcon(QString::fromLocal8Bit("左槽"), ui->supportIcon, model);
        updateIcon(QString::fromLocal8Bit("武器"), ui->weaponIcon, model);
    } catch (cv::Exception &e) {
        qCritical() << "Failed to load equipment icon. " << e.what();
        mainTray->showMessage(QString::fromLocal8Bit("分析失败"), //消息窗口标题
                              QString::fromLocal8Bit("显示装备图标时出现错误"), //消息内容
                              QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                              1000); //消息窗口显示时长
        this->mode = false;
        this->close();
        return;
    }

    if (model.isPhy) {
        QPixmap tmpQPm;
        tmpQPm.load("://resources/P_CRT.png");
        ui->minCrtIcon->setPixmap(tmpQPm);
        ui->minCrtLbl->setText(QString::fromLocal8Bit("进图物爆"));
        ui->maxCrtIcon->setPixmap(tmpQPm);
        ui->maxCrtLbl->setText(QString::fromLocal8Bit("物爆上限"));
        tmpQPm.load("://resources/STR.png");
        ui->selfAttrIcon->setPixmap(tmpQPm);
        ui->selfAttrLbl->setText(QString::fromLocal8Bit("角色力量"));
        ui->modelAttrIcon->setPixmap(tmpQPm);
        ui->modelAttrLbl->setText(QString::fromLocal8Bit("模板力量"));
        if (model.isInd) {
            tmpQPm.load("://resources/I_ATK.png");
            ui->selfAtkIcon->setPixmap(tmpQPm);
            ui->selfAtkLbl->setText(QString::fromLocal8Bit("角色独立"));
            ui->modelAtkIcon->setPixmap(tmpQPm);
            ui->modelAtkLbl->setText(QString::fromLocal8Bit("模板独立"));
        } else {
            tmpQPm.load("://resources/P_ATK.png");
            ui->selfAtkIcon->setPixmap(tmpQPm);
            ui->selfAtkLbl->setText(QString::fromLocal8Bit("角色物攻"));
            ui->modelAtkIcon->setPixmap(tmpQPm);
            ui->modelAtkLbl->setText(QString::fromLocal8Bit("模板物攻"));
        }
    } else {
        QPixmap tmpQPm;
        tmpQPm.load("://resources/M_CRT.png");
        ui->minCrtIcon->setPixmap(tmpQPm);
        ui->minCrtLbl->setText(QString::fromLocal8Bit("进图魔爆"));
        ui->maxCrtIcon->setPixmap(tmpQPm);
        ui->maxCrtLbl->setText(QString::fromLocal8Bit("魔爆上限"));
        tmpQPm.load("://resources/INT.png");
        ui->selfAttrIcon->setPixmap(tmpQPm);
        ui->selfAttrLbl->setText(QString::fromLocal8Bit("角色智力"));
        ui->modelAttrIcon->setPixmap(tmpQPm);
        ui->modelAttrLbl->setText(QString::fromLocal8Bit("模板智力"));
        if (model.isInd) {
            tmpQPm.load("://resources/I_ATK.png");
            ui->selfAtkIcon->setPixmap(tmpQPm);
            ui->selfAtkLbl->setText(QString::fromLocal8Bit("角色独立"));
            ui->modelAtkIcon->setPixmap(tmpQPm);
            ui->modelAtkLbl->setText(QString::fromLocal8Bit("模板独立"));
        } else {
            tmpQPm.load("://resources/M_ATK.png");
            ui->selfAtkIcon->setPixmap(tmpQPm);
            ui->selfAtkLbl->setText(QString::fromLocal8Bit("角色魔攻"));
            ui->modelAtkIcon->setPixmap(tmpQPm);
            ui->modelAtkLbl->setText(QString::fromLocal8Bit("模板魔攻"));
        }
    }

    ui->entryCntInfo->setText(QString::number(model.entryCnt));
    ui->reformCntInfo->setText(QString::number(model.reformCnt));
    ui->maxCrtInfo->setText(QString::asprintf("+%.1f%%", model.maxCrt));
    ui->minCrtInfo->setText(QString::asprintf("+%.1f%%", model.minCrt));
    ui->modelAtkInfo->setText(QString::number(int(model.atk)));
    ui->modelAttrInfo->setText(QString::number(int(model.attr)));
    ui->modelElementInfo->setText(QString::number(std::max(model.FIRE_OUT, std::max(model.ICE_OUT, std::max(model.LIGHT_OUT, model.DARK_OUT)))));
    ui->selfAtkInfo->setText(QString::number(atk));
    ui->selfAttrInfo->setText(QString::number(attr));
    ui->selfElementInfo->setText(QString::number(ELE));

    if (model.entryCnt == 7 || (model.entryCnt == 6 && model.reformCnt == 2) || (model.entryCnt == 4 && model.reformCnt == 5)) {
        ui->entryCntInfo->setStyleSheet("color: #96FF1E");
        ui->reformCntInfo->setStyleSheet("color: #96FF1E");
    } else {
        ui->entryCntInfo->setStyleSheet("color: red");
        ui->reformCntInfo->setStyleSheet("color: red");
    }

    if (atk >= int(model.atk)) {
        ui->selfAtkInfo->setStyleSheet("color: #96FF1E");
    } else {
        ui->selfAtkInfo->setStyleSheet("color: red");
    }

    if (attr >= int(model.attr)) {
        ui->selfAttrInfo->setStyleSheet("color: #96FF1E");
    } else {
        ui->selfAttrInfo->setStyleSheet("color: red");
    }

    if (model.minCrt >= 100) {
        ui->minCrtInfo->setStyleSheet("color: #96FF1E");
    } else if (model.minCrt < 95) {
        ui->minCrtInfo->setStyleSheet("color: red");
    } else {
        ui->minCrtInfo->setStyleSheet("color: white");
    }

    if (model.maxCrt >= 100) {
        ui->maxCrtInfo->setStyleSheet("color: #96FF1E");
    } else if (model.maxCrt < 95) {
        ui->maxCrtInfo->setStyleSheet("color: red");
    } else {
        ui->maxCrtInfo->setStyleSheet("color: white");
    }

    if (ELE >= std::max(model.FIRE_OUT, std::max(model.ICE_OUT, std::max(model.LIGHT_OUT, model.DARK_OUT)))) {
        ui->selfElementInfo->setStyleSheet("color: #96FF1E");
    } else {
        ui->selfElementInfo->setStyleSheet("color: red");
    }

    //ui->classLbl->setText(QString::fromLocal8Bit("[") + classVec.at(model.classID).name + QString::fromLocal8Bit("]"));
    if (classVec[classID].synergy == 1) setWindowIcon(QIcon("://resources/synergy.png"));
    else if (classVec[classID].synergy == -1) setWindowIcon(QIcon("://resources/dealer.png"));
    else setWindowIcon(QIcon("://resources/match_template.png"));

    QPixmap tmpQPm;
    tmpQPm.load("://resources/character/" + QString::number(model.classID) + ".png");
    ui->characterLbl->setPixmap(tmpQPm);

    QImage nameWhiteImg = drawText("[" + className + "]", Qt::white);
    QImage nameBlackImg = drawText("[" + className + "]", Qt::black);
    QImage nameImg(nameWhiteImg.width() + 2, nameWhiteImg.height() + 2, QImage::Format_ARGB32);
    nameImg.fill(qRgba(0, 0, 0, 0));
    QVector<int>offset_x{-1, 0, 1, 1, 1, 0, -1, -1};
    QVector<int>offset_y{-1, -1, -1, 0, 1, 1, 1, 0};
    QPainter painter(&nameImg);
    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
    for (int i = 0; i < 8; ++i) {
        int offx = 1 + offset_x.at(i), offy = 1 + offset_y.at(i);
        painter.drawImage(offx, offy, nameBlackImg);
    }
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.drawImage(1, 1, nameWhiteImg);
    ui->classLbl->setPixmap(QPixmap::fromImage(nameImg));

    int modelFinalELE = std::max(model.FIRE_OUT + model.FIRE_IN, std::max(model.ICE_OUT + model.ICE_IN,
                                 std::max(model.LIGHT_OUT + model.LIGHT_IN, model.DARK_OUT + model.DARK_IN)));
    double modelSysATTR = 0;
    Character modelbuffer(model);
    int baseATTR = model.isPhy ? classVec.at(model.classID).STR : classVec.at(model.classID).INT;
    if (SettingData::sysBufferIdx == 1) {
        if (model.classID == 60) {
            int l1 = model.passiveLVOUT.at(75) + 12;
            if (l1 > 40) l1 = 40;
            modelSysATTR = (model.attr / (1 + (2.0 * l1) / 100) - 275 - baseATTR) * 2.24 + 2295;
        } else {
            modelSysATTR = (model.attr - 275 - baseATTR) * 2.24 + 2295;
        }
    } else if (SettingData::sysBufferIdx == 2) {
        if (model.classID == 60) {
            int l1 = model.passiveLVOUT.at(75) + 12;
            if (l1 > 40) l1 = 40;
            modelSysATTR = (model.attr / (1 + (2.0 * l1) / 100) - 275 - baseATTR) * 1.35 + 7313;
        } else {
            modelSysATTR = (model.attr - 275 - baseATTR) * 1.35 + 7313;
        }
    }
    modelbuffer.attr += modelSysATTR;
    modelbuffer.atk += model.inatk;
    if (SettingData::isBuffer) {
        modelbuffer.attr += SettingData::bufferAttr;
        modelbuffer.atk += SettingData::bufferAtk;
    }
    {
        QString qstr = QString::number(model.classID);
        //qDebug() << qstr << endl;
        auto p = Factory<Equipment>::Instance().get(qstr);
        if (p != NULL) (*p)(modelbuffer);
        else {
            qCritical() << "Failed to find class indexed" << model.classID << ".";
            mainTray->showMessage(QString::fromLocal8Bit("分析失败"), //消息窗口标题
                                  QString::fromLocal8Bit("计算职业属性时出现错误"), //消息内容
                                  QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                                  1000); //消息窗口显示时长
            this->mode = false;
            this->close();
            return;
        }
    }
    double modelDMG = (1 + 0.004 * (int(model.attr) + int(modelbuffer.attr))) * (model.atk + modelbuffer.atk)
                      * (1.05 + 0.0045 * (modelFinalELE + (SettingData::isBuffer ? 60 : 0) - SettingData::antiELE));
    //qDebug() << model.attr << modelbuffer.attr << model.atk << modelbuffer.atk << modelFinalELE << modelDMG << endl;

    int charFIRE = FIRE + model.FIRE_IN, charICE = ICE + model.ICE_IN, charLIGHT = LIGHT + model.LIGHT_IN, charDARK = DARK + model.DARK_IN;
    double charFinalELE = 0;
    if (model.equipName->contains(QString::fromLocal8Bit("无形：守门人的灵魂甲胄")) && model.equipName->contains(QString::fromLocal8Bit("无欲：守门人的梦幻邪念"))
            && model.equipName->contains(QString::fromLocal8Bit("幻影：守门人的黑色面具"))) {
        charFIRE -= SettingData::guardELE * 3;
        charICE -= SettingData::guardELE * 3;
        charLIGHT -= SettingData::guardELE * 3;
        charDARK -= SettingData::guardELE * 3;

        charFIRE += 90;
        int minELE = std::min(charFIRE, std::min(charICE, std::min(charLIGHT, charDARK)));
        int maxELE = std::max(charFIRE, std::max(charICE, std::max(charLIGHT, charDARK)));
        if (maxELE - minELE >= 170) maxELE += 45;
        charFinalELE += maxELE;
        charFIRE -= 90;

        charICE += 90;
        minELE = std::min(charFIRE, std::min(charICE, std::min(charLIGHT, charDARK)));
        maxELE = std::max(charFIRE, std::max(charICE, std::max(charLIGHT, charDARK)));
        if (maxELE - minELE >= 170) maxELE += 45;
        charFinalELE += maxELE;
        charICE -= 90;

        charLIGHT += 90;
        minELE = std::min(charFIRE, std::min(charICE, std::min(charLIGHT, charDARK)));
        maxELE = std::max(charFIRE, std::max(charICE, std::max(charLIGHT, charDARK)));
        if (maxELE - minELE >= 170) maxELE += 45;
        charFinalELE += maxELE;
        charLIGHT -= 90;

        charDARK += 90;
        minELE = std::min(charFIRE, std::min(charICE, std::min(charLIGHT, charDARK)));
        maxELE = std::max(charFIRE, std::max(charICE, std::max(charLIGHT, charDARK)));
        if (maxELE - minELE >= 170) maxELE += 45;
        charFinalELE += maxELE;
        charDARK -= 90;

        charFinalELE /= 4.0;
    } else if ((model.equipName->contains(QString::fromLocal8Bit("无形：守门人的灵魂甲胄")) && model.equipName->contains(QString::fromLocal8Bit("无欲：守门人的梦幻邪念")))
               || (model.equipName->contains(QString::fromLocal8Bit("无欲：守门人的梦幻邪念")) && model.equipName->contains(QString::fromLocal8Bit("幻影：守门人的黑色面具")))
               || (model.equipName->contains(QString::fromLocal8Bit("幻影：守门人的黑色面具")) && model.equipName->contains(QString::fromLocal8Bit("无形：守门人的灵魂甲胄")))) {
        charFIRE -= SettingData::guardELE;
        charICE -= SettingData::guardELE;
        charLIGHT -= SettingData::guardELE;
        charDARK -= SettingData::guardELE;

        charFIRE += 30;
        int minELE = std::min(charFIRE, std::min(charICE, std::min(charLIGHT, charDARK)));
        int maxELE = std::max(charFIRE, std::max(charICE, std::max(charLIGHT, charDARK)));
        if (maxELE - minELE >= 170) maxELE += 15;
        charFinalELE += maxELE;
        charFIRE -= 30;

        charICE += 30;
        minELE = std::min(charFIRE, std::min(charICE, std::min(charLIGHT, charDARK)));
        maxELE = std::max(charFIRE, std::max(charICE, std::max(charLIGHT, charDARK)));
        if (maxELE - minELE >= 170) maxELE += 15;
        charFinalELE += maxELE;
        charICE -= 30;

        charLIGHT += 30;
        minELE = std::min(charFIRE, std::min(charICE, std::min(charLIGHT, charDARK)));
        maxELE = std::max(charFIRE, std::max(charICE, std::max(charLIGHT, charDARK)));
        if (maxELE - minELE >= 170) maxELE += 15;
        charFinalELE += maxELE;
        charLIGHT -= 30;

        charDARK += 30;
        minELE = std::min(charFIRE, std::min(charICE, std::min(charLIGHT, charDARK)));
        maxELE = std::max(charFIRE, std::max(charICE, std::max(charLIGHT, charDARK)));
        if (maxELE - minELE >= 170) maxELE += 15;
        charFinalELE += maxELE;
        charDARK -= 30;

        charFinalELE /= 4.0;
    } else {
        charFinalELE = std::max(charFIRE, std::max(charICE, std::max(charLIGHT, charDARK)));
    }
    double charSysATTR = 0;
    Character charbuffer(model);
    if (SettingData::sysBufferIdx == 1) {
        if (model.classID == 60) {
            int l1 = model.passiveLVOUT.at(75) + 12;
            if (l1 > 40) l1 = 40;
            charSysATTR = (attr / (1 + (2.0 * l1) / 100) - 275 - baseATTR) * 2.24 + 2295;
        } else {
            charSysATTR = (attr - 275 - baseATTR) * 2.24 + 2295;
        }
    } else if (SettingData::sysBufferIdx == 2) {
        if (model.classID == 60) {
            int l1 = model.passiveLVOUT.at(75) + 12;
            if (l1 > 40) l1 = 40;
            charSysATTR = (attr / (1 + (2.0 * l1) / 100) - 275 - baseATTR) * 1.35 + 7313;
        } else {
            charSysATTR = (attr - 275 - baseATTR) * 1.35 + 7313;
        }
    }
    charbuffer.attr += charSysATTR;
    charbuffer.atk += model.inatk;
    if (SettingData::isBuffer) {
        charbuffer.attr += SettingData::bufferAttr;
        charbuffer.atk += SettingData::bufferAtk;
    }
    {
        QString qstr = QString::number(model.classID);
        //qDebug() << qstr << endl;
        auto p = Factory<Equipment>::Instance().get(qstr);
        if (p != NULL) (*p)(charbuffer);
        else {
            qCritical() << "Failed to find class indexed" << model.classID << ".";
            mainTray->showMessage(QString::fromLocal8Bit("分析失败"), //消息窗口标题
                                  QString::fromLocal8Bit("计算职业属性时出现错误"), //消息内容
                                  QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                                  1000); //消息窗口显示时长
            this->mode = false;
            this->close();
            return;
        }
    }
    double charDMG = (1 + 0.004 * (attr + int(charbuffer.attr))) * (atk + charbuffer.atk)
                     * (1.05 + 0.0045 * (charFinalELE + (SettingData::isBuffer ? 60 : 0) - SettingData::antiELE));
    //qDebug() << attr << charbuffer.attr << atk << charbuffer.atk << charFinalELE << charDMG << endl;

    double DMGRatio = charDMG / modelDMG * 100.0 - 100.0;
    if (DMGRatio >= 0) {
        ui->resultLbl->setText(QString::asprintf("+%.1f%%", DMGRatio));
        ui->resultLbl->setStyleSheet("color: #96FF1E");
    } else {
        ui->resultLbl->setText(QString::asprintf("%.1f%%", DMGRatio));
        ui->resultLbl->setStyleSheet("color: red");
    }

    if (this->mode && SettingData::isAutoSave) {
        outQJO.insert("DMGRatio", DMGRatio);
        outQJO.insert("antiEle", SettingData::antiELE);
        outQJO.insert("buffAtk", SettingData::bufferAtk);
        outQJO.insert("buffAttr", SettingData::bufferAttr);
        outQJO.insert("buffEle", 60);
        outQJO.insert("charDMG", charDMG);
        outQJO.insert("classID", model.classID);
        outQJO.insert("className", className);
        outQJO.insert("entryCnt", model.entryCnt);
        outQJO.insert("reformCnt", model.reformCnt);
        outQJO.insert("modelDMG", modelDMG);
        QJsonObject modelQJO;
        modelQJO.insert("atk", model.atk);
        modelQJO.insert("atk_in", model.atk + modelbuffer.atk);
        modelQJO.insert("attr", model.attr);
        modelQJO.insert("attr_in", int(model.attr) + int(modelbuffer.attr));
        modelQJO.insert("dark", model.DARK_OUT);
        modelQJO.insert("dark_in", model.DARK_IN);
        modelQJO.insert("element", std::max(model.FIRE_OUT, std::max(model.ICE_OUT, std::max(model.LIGHT_OUT, model.DARK_OUT))));
        modelQJO.insert("element_in", modelFinalELE + (SettingData::isBuffer ? 60 : 0) - SettingData::antiELE);
        modelQJO.insert("fire", model.FIRE_OUT);
        modelQJO.insert("fire_in", model.FIRE_IN);
        modelQJO.insert("ice", model.ICE_OUT);
        modelQJO.insert("ice_in", model.ICE_IN);
        modelQJO.insert("light", model.LIGHT_OUT);
        modelQJO.insert("light_in", model.LIGHT_IN);
        outQJO.insert("model", modelQJO);
        QJsonObject charQJO;
        charQJO.insert("atk", atk);
        charQJO.insert("atk_in", atk + charbuffer.atk);
        charQJO.insert("attr", attr);
        charQJO.insert("attr_in", attr + int(charbuffer.attr));
        charQJO.insert("dark", DARK);
        charQJO.insert("element", ELE);
        charQJO.insert("element_in", charFinalELE + (SettingData::isBuffer ? 60 : 0) - SettingData::antiELE);
        charQJO.insert("fire", FIRE);
        charQJO.insert("ice", ICE);
        charQJO.insert("light", LIGHT);
        charQJO.insert("maxCrt", model.maxCrt);
        charQJO.insert("minCrt", model.minCrt);
        charQJO.insert("sysAttr", charSysATTR);
        outQJO.insert("character", charQJO);
        QJsonArray equipmentArray;
        for (QString str : qs) equipmentArray.push_back(str);
        outQJO.insert("equipmentName", equipmentArray);
        QJsonArray setArray;
        for (SetData sd : setVec) {
            if (setCnt.at(sd.id) >= 2) setArray.push_back(sd.name + " 2");
            if (setCnt.at(sd.id) >= 3) setArray.push_back(sd.name + " 3");
            if (setCnt.at(sd.id) >= 5) setArray.push_back(sd.name + " 5");
        }
        outQJO.insert("setName", setArray);
    }
}

QImage UserInfoWindow::drawText(const QString &str, const QColor &color) {
    QFont font;
    font.setFamily("simsun");
    font.setPixelSize(12);
    QFontMetrics fm(font);
    QVector<QImage> imgVec;
    int tot = 0;
    for (QChar c : str) {
        QSize size(fm.width(c), fm.height());
        QImage image(size, QImage::Format_ARGB32);
        if (color == Qt::white) image.fill(qRgba(0, 0, 0, 0));
        else image.fill(qRgba(255, 255, 255, 0));
        QPainter painter(&image);
        painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
        QPen pen = painter.pen();
        pen.setColor(color);
        painter.setPen(pen);
        painter.setFont(font);
        painter.drawText(image.rect(), Qt::AlignAbsolute, c);
        QRect qr = fm.tightBoundingRect(c);
        imgVec.push_back(image.copy(QRect(qr.x(), 0, qr.width(), fm.height())));
        tot += qr.width() + 1;
    }
    QSize size(tot - 1, fm.height());
    QImage image(size, QImage::Format_ARGB32);
    if (color == Qt::white) image.fill(qRgba(0, 0, 0, 0));
    else image.fill(qRgba(255, 255, 255, 0));
    QPainter painter(&image);
    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
    tot = 0;
    for (QImage img : imgVec) {
        painter.drawImage(tot, 0, img);
        tot += img.width() + 1;
    }
    return image;
}

void UserInfoWindow::updateIcon(const QString &key, QLabel *lbl, Character &model) {
    if (equipmentIcon[key].second > 0 && model.setCnt->at(equipmentIcon[key].second) <= 1) {
        lbl->setPixmap(CVA::cvMatToQPixmap(CVA::darken(equipmentIcon[key].first)));
    } else {
        lbl->setPixmap(CVA::cvMatToQPixmap(equipmentIcon[key].first));
    }
}

void UserInfoWindow::moveEvent(QMoveEvent *event) {
    QWidget::moveEvent(event);
    geo = this->geometry();
    firstFlag = false;
}

UserInfoWindow::~UserInfoWindow() {
    delete ui;
}
