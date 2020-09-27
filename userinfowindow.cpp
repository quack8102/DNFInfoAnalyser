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
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

extern QVector<ClassData> classVec;
extern Mat templateImg, selfInfoImg, classNameImg, charImg, bracketL, bracketR;
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
const double PSNRthreshold = 40.0;

QRect UserInfoWindow::geo;
bool UserInfoWindow::firstFlag = true;

UserInfoWindow::UserInfoWindow(QWidget *parent, const cv::Mat &srcImg, QSystemTrayIcon *tray, bool mode) :
    QWidget(parent),
    ui(new Ui::UserInfoWindow),
    mainTray(tray),
    setCnt(51) {
    classMenu = NULL;
    pantsMenu = NULL;
    ringMenu = NULL;
    supportMenu = NULL;

    this->mode = mode;
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_DeleteOnClose);

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
        //QMessageBox::warning(NULL, "分析失败", "检测不到角色面板");
        mainTray->showMessage("分析失败", //消息窗口标题
                              "检测不到角色面板", //消息内容
                              QSystemTrayIcon::MessageIcon::Warning, //消息窗口图标
                              1000); //消息窗口显示时长
        this->close();
        return;
    }

    saveImg = infoImg.clone();
    Rect selectClass;
    Mat classImg;
    try {
        selectClass = Rect(classPosX, classPosY, classWidth, classHeight);
        Mat tmpMat = infoImg(selectClass);
        for (int i = 0; i < tmpMat.rows; ++i) {
            uchar *data = tmpMat.ptr<uchar>(i);
            for (int j = 0; j < tmpMat.cols * 3; j += 3) {
                if (data[j] < 220 || data[j + 1] < 220 || data[j + 2] < 220) {
                    data[j] = data[j + 1] = data[j + 2] = 0;
                } else {
                    data[j] = data[j + 1] = data[j + 2] = 255;
                }
            }
        }
        //imwrite("tmpMat.png", tmpMat);
        Point p_l = CVA::matchTemplate(tmpMat, bracketL);
        Point p_r = CVA::matchTemplate(tmpMat, bracketR);
        selectClass = Rect(p_l.x, p_l.y, p_r.x - p_l.x + bracketR.cols, classHeight);
        classImg = tmpMat(selectClass);
        //imwrite("classImg.png", classImg);
    } catch (cv::Exception &e) {
        //QMessageBox::critical(NULL, "分析失败", "检测职业时出现错误");
        mainTray->showMessage("分析失败", //消息窗口标题
                              "检测职业时出现错误", //消息内容
                              QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                              1000); //消息窗口显示时长
        this->close();
        return;
    }

    Point p;
    try {
        p = CVA::matchTemplate(classNameImg, classImg);
    } catch (cv::Exception &e) {
        //QMessageBox::critical(NULL, "分析失败", "检测职业时出现错误");
        mainTray->showMessage("分析失败", //消息窗口标题
                              "检测职业时出现错误", //消息内容
                              QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                              1000); //消息窗口显示时长
        this->close();
        return;
    }
//qDebug() << "match point: (" << p.x << "," << p.y << ")" << endl;
    classID = p.y / titleHeight;

    Rect selectTitle;
    Mat titleImg;
    try {
        selectTitle = Rect(titlePosX, titlePosY, titleWidth, titleHeight);
        titleImg = infoImg(selectTitle);
    } catch (cv::Exception &e) {
        //QMessageBox::critical(NULL, "分析失败", "检测标题时出现错误");
        mainTray->showMessage("分析失败", //消息窗口标题
                              "检测标题时出现错误", //消息内容
                              QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                              1000); //消息窗口显示时长
        this->close();
        return;
    }
    for (int i = 0; i < titleImg.rows; ++i) {
        uchar *data = titleImg.ptr<uchar>(i);
        for (int j = 0; j < titleImg.cols * 3; j += 3) {
            if (data[j] > 60 && data[j + 1] > 60 && data[j + 2] > 60) {
                data[j] = data[j + 1] = data[j + 2] = 255;
            } else {
                data[j] = data[j + 1] = data[j + 2] = 0;
            }
        }
    }
    double score = 0.0;
    try {
        score = CVA::getPSNR(titleImg, selfInfoImg);
    } catch (cv::Exception &e) {
        //QMessageBox::critical(NULL, "分析失败", "检测标题时出现错误");
        mainTray->showMessage("分析失败", //消息窗口标题
                              "检测标题时出现错误", //消息内容
                              QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                              1000); //消息窗口显示时长
        this->close();
        return;
    }

    //qDebug() << score << endl;
    QVector<LayoutData> *layout;
    if (score > PSNRthreshold) layout = &selfVec;
    else layout = &otherVec;

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
                //QMessageBox::critical(NULL, "分析失败", "检测装备时出现错误");
                mainTray->showMessage("分析失败", //消息窗口标题
                                      "检测装备时出现错误", //消息内容
                                      QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                                      1000); //消息窗口显示时长
                this->close();
                return;
            }
            int index = mp.y / iconHeight;
            qts << data.name << tr("：") << equipmentInfoVec[data.id][index].name << endl;
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
                mainTray->showMessage("分析失败", //消息窗口标题
                                      "检测属性时出现错误", //消息内容
                                      QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                                      1000); //消息窗口显示时长
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
                qts << data.name << tr("：");
                for (pair<int, QString> v : resVec)
                    ss = ss + v.second;
            } catch (cv::Exception &e) {
                //QMessageBox::critical(NULL, "分析失败", "检测属性时出现错误");
                mainTray->showMessage("分析失败", //消息窗口标题
                                      "检测属性时出现错误", //消息内容
                                      QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                                      1000); //消息窗口显示时长
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
    //qDebug() << infoString;
//qDebug() << STR << " " << INT << " " << P_ATK << " " << M_ATK << " " << I_ATK << " " << P_CRT << " " << M_CRT << endl;

    decideFlags(classVec[classID], isPhy, isInd, aType);
    collectAttr(attr, atk, crt);

    ui->characterLbl->installEventFilter(this);
    ui->pantsIcon->installEventFilter(this);
    ui->ringIcon->installEventFilter(this);
    ui->supportIcon->installEventFilter(this);

    if (qs.contains(tr("无形：奈克斯的灵魂仪服")) || qs.contains(tr("无形：暗杀者的灵魂残念")) || qs.contains(tr("无形：卢克西的灵魂狂气"))
            || qs.contains(tr("无形：守门人的灵魂甲胄")) || qs.contains(tr("无形：洛多斯的灵魂意志"))) {
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
            pantsMenu->actions().at(pantsid)->setText(pantsMenu->actions().at(pantsid)->text() + " √");
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

    if (qs.contains(tr("无欲：奈克斯的梦幻黑暗")) || qs.contains(tr("无欲：暗杀者的梦幻痕迹")) || qs.contains(tr("无欲：卢克西的梦幻约定"))
            || qs.contains(tr("无欲：守门人的梦幻邪念")) || qs.contains(tr("无欲：洛多斯的梦幻根源"))) {
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
            ringMenu->actions().at(ringid)->setText(ringMenu->actions().at(ringid)->text() + " √");
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

    if (qs.contains(tr("幻影：奈克斯的黑色之息")) || qs.contains(tr("幻影：暗杀者的黑色剑鞘")) || qs.contains(tr("幻影：卢克西的黑色鬼神缚"))
            || qs.contains(tr("幻影：守门人的黑色面具")) || qs.contains(tr("幻影：洛多斯的黑色核心"))) {
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
            supportMenu->actions().at(supportid)->setText(supportMenu->actions().at(supportid)->text() + " √");
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

    if (classID == 9 || classID == 13) {
        classMenu = new QMenu(this);
        QAction *tmpAction1 = new QAction(this);
        QAction *tmpAction2 = new QAction(this);
        classMenu->addAction(tmpAction1);
        classMenu->addAction(tmpAction2);
        auto setActions = [ = ]() {
            tmpAction1->setText(tr("男气功"));
            tmpAction2->setText(tr("女气功"));
            if (classID == 9) {
                tmpAction1->setText(tmpAction1->text() + " √");
            } else {
                tmpAction2->setText(tmpAction2->text() + " √");
            }
        };
        setActions();
        connect(tmpAction1, &QAction::triggered, [ = ]() {
            classID = 9;
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction2, &QAction::triggered, [ = ]() {
            classID = 13;
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
    }

    if (classID == 10 || classID == 14) {
        classMenu = new QMenu(this);
        QAction *tmpAction1 = new QAction(this);
        QAction *tmpAction2 = new QAction(this);
        classMenu->addAction(tmpAction1);
        classMenu->addAction(tmpAction2);
        auto setActions = [ = ]() {
            tmpAction1->setText(tr("男武极"));
            tmpAction2->setText(tr("女武神"));
            if (classID == 10) {
                tmpAction1->setText(tmpAction1->text() + " √");
            } else {
                tmpAction2->setText(tmpAction2->text() + " √");
            }
        };
        setActions();
        connect(tmpAction1, &QAction::triggered, [ = ]() {
            classID = 10;
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction2, &QAction::triggered, [ = ]() {
            classID = 14;
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
    }

    if (classID == 11 || classID == 15) {
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
            tmpAction1->setText(tr("物理男街霸"));
            tmpAction2->setText(tr("魔法男街霸"));
            tmpAction3->setText(tr("物理女毒王"));
            tmpAction4->setText(tr("魔法女毒王"));
            if (classID == 11) {
                if (isPhy) tmpAction1->setText(tmpAction1->text() + " √");
                else tmpAction2->setText(tmpAction2->text() + " √");
            } else {
                if (isPhy) tmpAction3->setText(tmpAction3->text() + " √");
                else tmpAction4->setText(tmpAction4->text() + " √");
            }
        };
        setActions();
        connect(tmpAction1, &QAction::triggered, [ = ]() {
            classID = 11;
            isPhy = true;
            collectAttr(attr, atk, crt);
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction2, &QAction::triggered, [ = ]() {
            classID = 11;
            isPhy = false;
            collectAttr(attr, atk, crt);
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction3, &QAction::triggered, [ = ]() {
            classID = 15;
            isPhy = true;
            collectAttr(attr, atk, crt);
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction4, &QAction::triggered, [ = ]() {
            classID = 15;
            isPhy = false;
            collectAttr(attr, atk, crt);
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
    }

    if (classID == 12 || classID == 16) {
        classMenu = new QMenu(this);
        QAction *tmpAction1 = new QAction(this);
        QAction *tmpAction2 = new QAction(this);
        classMenu->addAction(tmpAction1);
        classMenu->addAction(tmpAction2);
        auto setActions = [ = ]() {
            tmpAction1->setText(tr("男柔道"));
            tmpAction2->setText(tr("女柔道"));
            if (classID == 12) {
                tmpAction1->setText(tmpAction1->text() + " √");
            } else {
                tmpAction2->setText(tmpAction2->text() + " √");
            }
        };
        setActions();
        connect(tmpAction1, &QAction::triggered, [ = ]() {
            classID = 12;
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction2, &QAction::triggered, [ = ]() {
            classID = 16;
            setActions();
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
    }

    if (classID == 20 || classID == 24 || classID == 32) {
        classMenu = new QMenu(this);
        QAction *tmpAction1 = new QAction(this);
        QAction *tmpAction2 = new QAction(this);
        classMenu->addAction(tmpAction1);
        classMenu->addAction(tmpAction2);
        auto setActions = [ = ]() {
            tmpAction1->setText(tr("物理"));
            tmpAction2->setText(tr("魔法"));
            if (isPhy) {
                tmpAction1->setText(tmpAction1->text() + " √");
            } else {
                tmpAction2->setText(tmpAction2->text() + " √");
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
        classMenu = new QMenu(this);
        QAction *tmpAction1 = new QAction(this);
        QAction *tmpAction2 = new QAction(this);
        QAction *tmpAction3 = new QAction(this);
        classMenu->addAction(tmpAction1);
        classMenu->addAction(tmpAction2);
        classMenu->addAction(tmpAction3);
        auto setActions = [ = ]() {
            tmpAction1->setText(tr("魔法布甲"));
            tmpAction2->setText(tr("物理重甲"));
            tmpAction3->setText(tr("物理板甲"));
        };
        setActions();
        if (isPhy) {
            tmpAction2->setText(tmpAction2->text() + " √");
        } else {
            tmpAction1->setText(tmpAction1->text() + " √");
        }
        connect(tmpAction1, &QAction::triggered, [ = ]() {
            isPhy = false;
            aType = 1;
            collectAttr(attr, atk, crt);
            setActions();
            tmpAction1->setText(tmpAction1->text() + " √");
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction2, &QAction::triggered, [ = ]() {
            isPhy = true;
            aType = 4;
            collectAttr(attr, atk, crt);
            setActions();
            tmpAction2->setText(tmpAction2->text() + " √");
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction3, &QAction::triggered, [ = ]() {
            isPhy = true;
            aType = 5;
            collectAttr(attr, atk, crt);
            setActions();
            tmpAction3->setText(tmpAction3->text() + " √");
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
    }

    if (classID == 60) {
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
            tmpAction1->setText(tr("魔法布甲"));
            tmpAction2->setText(tr("物理轻甲"));
            tmpAction3->setText(tr("物理重甲"));
            tmpAction4->setText(tr("魔法板甲"));
        };
        setActions();
        if (isPhy) {
            tmpAction2->setText(tmpAction2->text() + " √");
        } else {
            tmpAction1->setText(tmpAction1->text() + " √");
        }
        connect(tmpAction1, &QAction::triggered, [ = ]() {
            isPhy = false;
            aType = 1;
            collectAttr(attr, atk, crt);
            setActions();
            tmpAction1->setText(tmpAction1->text() + " √");
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction2, &QAction::triggered, [ = ]() {
            isPhy = true;
            aType = 3;
            collectAttr(attr, atk, crt);
            setActions();
            tmpAction2->setText(tmpAction2->text() + " √");
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction3, &QAction::triggered, [ = ]() {
            isPhy = true;
            aType = 4;
            collectAttr(attr, atk, crt);
            setActions();
            tmpAction3->setText(tmpAction3->text() + " √");
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
        connect(tmpAction4, &QAction::triggered, [ = ]() {
            isPhy = false;
            aType = 5;
            collectAttr(attr, atk, crt);
            setActions();
            tmpAction4->setText(tmpAction4->text() + " √");
            Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
            refresh(model);
        });
    }

    Character model(classID, isPhy ? classVec[classID].STR : classVec[classID].INT, crt, isPhy, isInd, wType, aType, setCnt, qs);
    refresh(model);
    this->show();
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
        if (!dir.exists("./save/" + suffix)) {
            if (dir.mkpath("./save/" + suffix)) {
                QPixmap sqpm = CVA::cvMatToQPixmap(saveImg);
                sqpm.save("./save/" + suffix + "/character_" + suffix + ".png");
                QFile file("./save/" + suffix + "/result_" + suffix + ".txt");
                if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    //qDebug() << "Can't open the file!" << endl;
                    QMessageBox::critical(NULL, "错误", "文件打开失败");
                } else {
                    QTextStream stream(&file);
                    //stream.setCodec("UTF-8");
                    stream << classVec.at(classID).name << " " << ui->resultLbl->text() << endl
                           << ui->selfAttrInfo->text() << " " << ui->modelAttrInfo->text() << endl
                           << ui->selfAtkInfo->text() << " " << ui->modelAtkInfo->text() << endl
                           << ui->selfElementInfo->text() << " " << ui->modelElementInfo->text() << endl;
                    file.close();
                }
            } else {
                mainTray->showMessage("保存失败", //消息窗口标题
                                      "创建文件夹时出现错误", //消息内容
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
    for (AttrData ad : SettingData::vec) {
        ad(model);
    }
    for (QString en : qs) {
        auto p = Factory<Equipment>::Instance().get(en);
        if (p == NULL) {
            mainTray->showMessage("分析失败", //消息窗口标题
                                  "计算装备属性时出现错误", //消息内容
                                  QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                                  1000); //消息窗口显示时长
            this->close();
            return;
        }
        (*p)(model);
    }
    for (SetData sd : setVec) {
        auto p = Factory<Equipment>::Instance().get(sd.name);
        if (p == NULL) {
            mainTray->showMessage("分析失败", //消息窗口标题
                                  "计算套装属性时出现错误", //消息内容
                                  QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                                  1000); //消息窗口显示时长
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
            mainTray->showMessage("分析失败", //消息窗口标题
                                  "计算职业属性时出现错误", //消息内容
                                  QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                                  1000); //消息窗口显示时长
            this->close();
            return;
        }
    }
    //model.showDetail();
    QString qstr;
    QTextStream stream(&qstr);
    stream << tr("人物主属性：") << attr << tr("，模板主属性：") << int(model.attr) << endl;
    stream << tr("人物攻击力：") << atk << tr("，模板攻击力：");
    if (model.isInd) {
        stream << int(model.atk) << endl;
    } else {
        stream << int(model.atk * (1 + int(model.attr) / 250.0)) << endl;
    }
    stream << tr("人物进图暴击率：") << model.minCrt << tr("% ~ ") << model.maxCrt << tr("%") << endl;
    stream << tr("模特属强：") << std::max(model.FIRE_OUT, std::max(model.ICE_OUT, std::max(model.LIGHT_OUT, model.DARK_OUT))) << endl;
    stream << tr("人物词条数：") << model.entryCnt << tr("，智慧产物数：") << model.reformCnt << endl;
    //ui->infoLbl->setText(qstr);

    //ui->classLbl->setText("职业： " + classVec[classID].name);
    //if (classVec[classID].synergy == 1) ui->synergyLbl->setText("协同C");
    //else if (classVec[classID].synergy == -1) ui->synergyLbl->setText("纯C");
    //else ui->synergyLbl->setText("可切换");

    QFont font("宋体");
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

    QFont bigFont("宋体");
    bigFont.setBold(true);
    bigFont.setPixelSize(25);
    ui->resultLbl->setFont(bigFont);

    try {
        updateIcon(tr("腰带"), ui->beltIcon, model);
        updateIcon(tr("手镯"), ui->braceletIcon, model);
        updateIcon(tr("上衣"), ui->coatIcon, model);
        updateIcon(tr("耳环"), ui->earringIcon, model);
        updateIcon(tr("右槽"), ui->magicstoneIcon, model);
        updateIcon(tr("肩"), ui->neckIcon, model);
        updateIcon(tr("项链"), ui->necklaceIcon, model);
        updateIcon(tr("裤子"), ui->pantsIcon, model);
        updateIcon(tr("戒指"), ui->ringIcon, model);
        updateIcon(tr("鞋子"), ui->shoesIcon, model);
        updateIcon(tr("左槽"), ui->supportIcon, model);
        updateIcon(tr("武器"), ui->weaponIcon, model);
    } catch (cv::Exception &e) {
        mainTray->showMessage("分析失败", //消息窗口标题
                              "显示装备图标时出现错误", //消息内容
                              QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                              1000); //消息窗口显示时长
        this->close();
        return;
    }

    if (model.isPhy) {
        QPixmap tmpQPm;
        tmpQPm.load("://resources/P_CRT.png");
        ui->minCrtIcon->setPixmap(tmpQPm);
        ui->minCrtLbl->setText(tr("进图物爆"));
        ui->maxCrtIcon->setPixmap(tmpQPm);
        ui->maxCrtLbl->setText(tr("物爆上限"));
        tmpQPm.load("://resources/STR.png");
        ui->selfAttrIcon->setPixmap(tmpQPm);
        ui->selfAttrLbl->setText(tr("角色力量"));
        ui->modelAttrIcon->setPixmap(tmpQPm);
        ui->modelAttrLbl->setText(tr("模板力量"));
        if (model.isInd) {
            tmpQPm.load("://resources/I_ATK.png");
            ui->selfAtkIcon->setPixmap(tmpQPm);
            ui->selfAtkLbl->setText(tr("角色独立"));
            ui->modelAtkIcon->setPixmap(tmpQPm);
            ui->modelAtkLbl->setText(tr("模板独立"));
        } else {
            tmpQPm.load("://resources/P_ATK.png");
            ui->selfAtkIcon->setPixmap(tmpQPm);
            ui->selfAtkLbl->setText(tr("角色物攻"));
            ui->modelAtkIcon->setPixmap(tmpQPm);
            ui->modelAtkLbl->setText(tr("模板物攻"));
        }
    } else {
        QPixmap tmpQPm;
        tmpQPm.load("://resources/M_CRT.png");
        ui->minCrtIcon->setPixmap(tmpQPm);
        ui->minCrtLbl->setText(tr("进图魔爆"));
        ui->maxCrtIcon->setPixmap(tmpQPm);
        ui->maxCrtLbl->setText(tr("魔爆上限"));
        tmpQPm.load("://resources/INT.png");
        ui->selfAttrIcon->setPixmap(tmpQPm);
        ui->selfAttrLbl->setText(tr("角色智力"));
        ui->modelAttrIcon->setPixmap(tmpQPm);
        ui->modelAttrLbl->setText(tr("模板智力"));
        if (model.isInd) {
            tmpQPm.load("://resources/I_ATK.png");
            ui->selfAtkIcon->setPixmap(tmpQPm);
            ui->selfAtkLbl->setText(tr("角色独立"));
            ui->modelAtkIcon->setPixmap(tmpQPm);
            ui->modelAtkLbl->setText(tr("模板独立"));
        } else {
            tmpQPm.load("://resources/M_ATK.png");
            ui->selfAtkIcon->setPixmap(tmpQPm);
            ui->selfAtkLbl->setText(tr("角色魔攻"));
            ui->modelAtkIcon->setPixmap(tmpQPm);
            ui->modelAtkLbl->setText(tr("模板魔攻"));
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
    }

    if (model.maxCrt >= 100) {
        ui->maxCrtInfo->setStyleSheet("color: #96FF1E");
    } else if (model.minCrt < 95) {
        ui->maxCrtInfo->setStyleSheet("color: red");
    }

    if (ELE >= std::max(model.FIRE_OUT, std::max(model.ICE_OUT, std::max(model.LIGHT_OUT, model.DARK_OUT)))) {
        ui->selfElementInfo->setStyleSheet("color: #96FF1E");
    } else {
        ui->selfElementInfo->setStyleSheet("color: red");
    }

    //ui->classLbl->setText(tr("[") + classVec.at(model.classID).name + tr("]"));
    if (classVec[classID].synergy == 1) setWindowIcon(QIcon("://resources/synergy.png"));
    else if (classVec[classID].synergy == -1) setWindowIcon(QIcon("://resources/dealer.png"));
    else setWindowIcon(QIcon("://resources/match_template.png"));

    QPixmap tmpQPm;
    tmpQPm.load("://resources/character/" + QString::number(model.classID) + ".png");
    ui->characterLbl->setPixmap(tmpQPm);

    QImage nameWhiteImg = drawText("[" + classVec.at(model.classID).name + "]", Qt::white);
    QImage nameBlackImg = drawText("[" + classVec.at(model.classID).name + "]", Qt::black);
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
            mainTray->showMessage("分析失败", //消息窗口标题
                                  "计算职业属性时出现错误", //消息内容
                                  QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                                  1000); //消息窗口显示时长
            this->close();
            return;
        }
    }
    double modelDMG = (1 + 0.004 * (int(model.attr) + int(modelbuffer.attr))) * (model.atk + modelbuffer.atk)
                      * (1.05 + 0.0045 * (modelFinalELE + (SettingData::isBuffer ? 60 : 0) - SettingData::antiELE));
    //qDebug() << model.attr << modelbuffer.attr << model.atk << modelbuffer.atk << modelFinalELE << modelDMG << endl;

    int charFIRE = FIRE + model.FIRE_IN, charICE = ICE + model.ICE_IN, charLIGHT = LIGHT + model.LIGHT_IN, charDARK = DARK + model.DARK_IN;
    double charFinalELE = 0;
    if (model.equipName->contains(tr("无形：守门人的灵魂甲胄")) && model.equipName->contains(tr("无欲：守门人的梦幻邪念"))
            && model.equipName->contains(tr("幻影：守门人的黑色面具"))) {
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
    } else if ((model.equipName->contains(tr("无形：守门人的灵魂甲胄")) && model.equipName->contains(tr("无欲：守门人的梦幻邪念")))
               || (model.equipName->contains(tr("无欲：守门人的梦幻邪念")) && model.equipName->contains(tr("幻影：守门人的黑色面具")))
               || (model.equipName->contains(tr("幻影：守门人的黑色面具")) && model.equipName->contains(tr("无形：守门人的灵魂甲胄")))) {
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
            mainTray->showMessage("分析失败", //消息窗口标题
                                  "计算职业属性时出现错误", //消息内容
                                  QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                                  1000); //消息窗口显示时长
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
}

QImage UserInfoWindow::drawText(const QString &str, const QColor &color) {
    QFont font;
    font.setFamily("宋体");
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
