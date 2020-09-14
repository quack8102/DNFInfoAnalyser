#include "userinfowindow.h"
#include "ui_userinfowindow.h"
#include "cvalgorithm.h"
#include "csvdataparser.h"
#include "factory.h"
#include "equipment.h"
#include <vector>
#include <QComboBox>
#include <QMessageBox>
#include <QPalette>
#include <QBitmap>
#include <QMouseEvent>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

extern QVector<ClassData> classVec;
extern Mat selfInfoImg, classNameImg, charImg;
extern QVector<LayoutData> selfVec, otherVec;
extern QVector<SetData> setVec;
extern QVector<CharData> charVec;
extern QVector<QVector<EquipmentData> > equipmentInfoVec, weaponInfoVec;
extern QVector<Mat> equipmentImgVec, weaponImgVec;

const int classPosX = 91, classPosY = 195, classWidth = 96, classHeight = 14;
const int titlePosX = 108, titlePosY = 5, titleWidth = 64, titleHeight = 14;
const int iconWidth = 28, iconHeight = 28;
const int charWidth = 8, charHeight = 10;
const double PSNRthreshold = 40.0;

QRect UserInfoWindow::geo;
bool UserInfoWindow::firstFlag = true;

UserInfoWindow::UserInfoWindow(QWidget *parent, const cv::Mat &infoImg, QSystemTrayIcon *tray) :
    QWidget(parent),
    ui(new Ui::UserInfoWindow),
    mainTray(tray),
    setCnt(51) {
    tmpMenu = NULL;
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    if (!firstFlag) setGeometry(geo);

    QPixmap bgImages("://resources/bg.png");
    QPalette bgPalette = this->palette();
    bgPalette.setBrush(QPalette::Background, bgImages);
    this->setPalette(bgPalette);

    setMask(bgImages.mask());

    qs.clear();
    equipmentIcon.clear();
    Rect selectClass;
    Mat classImg;
    try {
        selectClass = Rect(classPosX, classPosY, classWidth, classHeight);
        classImg = infoImg(selectClass);
    } catch (cv::Exception &e) {
        //QMessageBox::critical(NULL, "分析失败", "检测职业时出现错误");
        mainTray->showMessage("分析失败", //消息窗口标题
                              "检测职业时出现错误", //消息内容
                              QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                              1000); //消息窗口显示时长
    }
    int rows = classImg.rows;
    int cols = classImg.cols;
    for (int i = 0; i < rows; ++i) {
        uchar *data = classImg.ptr<uchar>(i);
        for (int j = 0; j < cols * 3; j += 3) {
            if (data[j] < 200 || data[j + 1] < 200 || data[j + 2] < 200) {
                data[j] = data[j + 1] = data[j + 2] = 0;
            } else {
                data[j] = data[j + 1] = data[j + 2] = 255;
            }
        }
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
    }
    rows = titleImg.rows;
    cols = titleImg.cols;
    for (int i = 0; i < rows; ++i) {
        uchar *data = titleImg.ptr<uchar>(i);
        for (int j = 0; j < cols * 3; j += 3) {
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
            }
            for (int i = 0; i < tmpMat.rows; ++i) {
                uchar *data = tmpMat.ptr<uchar>(i);
                for (int j = 0; j < tmpMat.cols * 3; j += 3) {
                    if (int(data[j]) + int(data[j + 1]) + int(data[j + 2]) > 127) {
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
            }
            qts << ss << endl;
            if (data.id == 13) STR = ss.toInt();
            else if (data.id == 14) INT = ss.toInt();
            else if (data.id == 15) P_ATK = ss.toInt();
            else if (data.id == 16) M_ATK = ss.toInt();
            else if (data.id == 17) I_ATK = ss.toInt();
            else if (data.id == 18) P_CRT = ss.toDouble();
            else if (data.id == 19) M_CRT = ss.toDouble();
        }
    }
    //qDebug() << infoString;
    //qDebug() << STR << " " << INT << " " << P_ATK << " " << M_ATK << " " << I_ATK << " " << P_CRT << " " << M_CRT << endl;

    decideFlags(classVec[classID], isPhy, isInd, aType);
    collectAttr(attr, atk, crt);

    ui->characterLbl->installEventFilter(this);

    if (classID == 9 || classID == 13) {
        tmpMenu = new QMenu(this);
        QAction *tmpAction1 = new QAction(this);
        QAction *tmpAction2 = new QAction(this);
        tmpMenu->addAction(tmpAction1);
        tmpMenu->addAction(tmpAction2);
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
        tmpMenu = new QMenu(this);
        QAction *tmpAction1 = new QAction(this);
        QAction *tmpAction2 = new QAction(this);
        tmpMenu->addAction(tmpAction1);
        tmpMenu->addAction(tmpAction2);
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
        tmpMenu = new QMenu(this);
        QAction *tmpAction1 = new QAction(this);
        QAction *tmpAction2 = new QAction(this);
        QAction *tmpAction3 = new QAction(this);
        QAction *tmpAction4 = new QAction(this);
        tmpMenu->addAction(tmpAction1);
        tmpMenu->addAction(tmpAction2);
        tmpMenu->addAction(tmpAction3);
        tmpMenu->addAction(tmpAction4);
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
        tmpMenu = new QMenu(this);
        QAction *tmpAction1 = new QAction(this);
        QAction *tmpAction2 = new QAction(this);
        tmpMenu->addAction(tmpAction1);
        tmpMenu->addAction(tmpAction2);
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
        tmpMenu = new QMenu(this);
        QAction *tmpAction1 = new QAction(this);
        QAction *tmpAction2 = new QAction(this);
        tmpMenu->addAction(tmpAction1);
        tmpMenu->addAction(tmpAction2);
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
        tmpMenu = new QMenu(this);
        QAction *tmpAction1 = new QAction(this);
        QAction *tmpAction2 = new QAction(this);
        QAction *tmpAction3 = new QAction(this);
        tmpMenu->addAction(tmpAction1);
        tmpMenu->addAction(tmpAction2);
        tmpMenu->addAction(tmpAction3);
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
        tmpMenu = new QMenu(this);
        QAction *tmpAction1 = new QAction(this);
        QAction *tmpAction2 = new QAction(this);
        QAction *tmpAction3 = new QAction(this);
        QAction *tmpAction4 = new QAction(this);
        tmpMenu->addAction(tmpAction1);
        tmpMenu->addAction(tmpAction2);
        tmpMenu->addAction(tmpAction3);
        tmpMenu->addAction(tmpAction4);
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
}

bool UserInfoWindow::eventFilter(QObject *obj, QEvent *event) {
    if (qobject_cast<QLabel *>(obj) == ui->characterLbl && event->type() == QEvent::MouseButtonRelease) {
        if (tmpMenu != NULL) {
            QMouseEvent *e = static_cast<QMouseEvent *>(event);
            tmpMenu->exec(e->globalPos());
        }
        return true;
    } else {
        return false;
        //return QMainWindow::eventFilter(obj, event);
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
    for (QString en : qs) {
        auto p = Factory<Equipment>::Instance().get(en);
        if (p == NULL) {
            mainTray->showMessage("分析失败", //消息窗口标题
                                  "计算装备属性时出现错误", //消息内容
                                  QSystemTrayIcon::MessageIcon::Critical, //消息窗口图标
                                  1000); //消息窗口显示时长
            continue;
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
            continue;
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
    if (model.isInd) {
        ui->modelAtkInfo->setText(QString::number(int(model.atk)));
    } else {
        ui->modelAtkInfo->setText(QString::number(int(model.atk * (1 + int(model.attr) / 250.0))));
    }
    ui->modelAttrInfo->setText(QString::number(int(model.attr)));
    ui->modelElementInfo->setText(QString::number(std::max(model.FIRE_OUT, std::max(model.ICE_OUT, std::max(model.LIGHT_OUT, model.DARK_OUT)))));
    ui->selfAtkInfo->setText(QString::number(atk));
    ui->selfAttrInfo->setText(QString::number(attr));
    ui->selfElementInfo->setText(tr("???"));

    if (model.entryCnt == 7 || (model.entryCnt == 6 && model.reformCnt == 2) || (model.entryCnt == 4 && model.reformCnt == 5)) {
        ui->entryCntInfo->setStyleSheet("color: #96FF1E");
        ui->reformCntInfo->setStyleSheet("color: #96FF1E");
    } else {
        ui->entryCntInfo->setStyleSheet("color: red");
        ui->reformCntInfo->setStyleSheet("color: red");
    }

    if (atk >= (model.isInd ? int(model.atk) : int(model.atk * (1 + int(model.attr) / 250.0)))) {
        ui->selfAtkInfo->setStyleSheet("color: #96FF1E");
    } else {
        ui->selfAtkInfo->setStyleSheet("color: red");
    }

    if (attr >= int(model.attr)) {
        ui->selfAttrInfo->setStyleSheet("color: #96FF1E");
    } else {
        ui->selfAttrInfo->setStyleSheet("color: red");
    }

    if (model.minCrt >= 97) {
        ui->minCrtInfo->setStyleSheet("color: #96FF1E");
    } else {
        ui->minCrtInfo->setStyleSheet("color: red");
    }

    if (model.maxCrt >= 97) {
        ui->maxCrtInfo->setStyleSheet("color: #96FF1E");
    } else {
        ui->maxCrtInfo->setStyleSheet("color: red");
    }

    ui->classLbl->setText(tr("[") + classVec.at(model.classID).name + tr("]"));
    if (classVec[classID].synergy == 1) setWindowIcon(QIcon("://resources/synergy.png"));
    else if (classVec[classID].synergy == -1) setWindowIcon(QIcon("://resources/dealer.png"));
    else setWindowIcon(QIcon("://resources/match_template.png"));

    QPixmap tmpQPm;
    tmpQPm.load("://resources/character/" + QString::number(model.classID) + ".png");
    ui->characterLbl->setPixmap(tmpQPm);
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
    geo = this->frameGeometry();
    firstFlag = false;
}

UserInfoWindow::~UserInfoWindow() {
    delete ui;
}
