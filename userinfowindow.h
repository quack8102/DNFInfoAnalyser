#ifndef USERINFOWINDOW_H
#define USERINFOWINDOW_H

#include <QWidget>
#include <QMap>
#include <QSystemTrayIcon>
#include <QLabel>
#include <QEvent>
#include <QMenu>
#include "character.h"
#include "csvdataparser.h"

namespace Ui {
class UserInfoWindow;
}

class UserInfoWindow : public QWidget {
    Q_OBJECT

  public:
    explicit UserInfoWindow(QWidget *parent, const cv::Mat &infoImg, QSystemTrayIcon *tray);
    ~UserInfoWindow();

  protected:
    bool eventFilter(QObject *obj, QEvent *event);

  private:
    Ui::UserInfoWindow *ui;
    QSystemTrayIcon *mainTray;
    void decideFlags(const ClassData &cd, bool &isPhy, bool &isInd, int &armorType);
    void collectAttr(int &attr, int &atk, double &crt);
    void refresh(Character &model);
    void updateIcon(const QString &key, QLabel *lbl, Character &model);
    void moveEvent(QMoveEvent *event);
    int classID;
    int STR, INT, P_ATK, M_ATK, I_ATK;
    double P_CRT, M_CRT;
    bool isPhy, isInd;
    int attr, atk, aType, wType;
    double crt;
    QSet<QString> qs;
    QVector<int> setCnt;
    QMap<QString, std::pair<cv::Mat, int> > equipmentIcon;
    static QRect geo;
    static bool firstFlag;
    QMenu *tmpMenu;
};

#endif // USERINFOWINDOW_H
