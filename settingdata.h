#ifndef SETTINGDATA_H
#define SETTINGDATA_H

#include <QString>
#include <QVector>
#include <MyGlobalShortCut/MyGlobalShortCut.h>
#include <MyGlobalShortCut/mymousehook.h>
#include <QFontDatabase>
#include "mainwindow.h"
#include "character.h"
#include "messagewindow.h"

class AttrData {
  public:
    QString name;
    bool indungeon;
    int STR, INT, P_ATK, M_ATK, I_ATK, ELE, passiveL, passiveR, passiveC, activeL, activeR, activeC;
    AttrData() {}
    AttrData(const QStringList &li);
    QString toQString();
    void operator () (Character &model);
};

class SettingData {
  public:
    static QString hotkeyStr;
    static bool isAutoSave, isHero, isBuffer;
    static int hotkeyType, ampLV, reformLV, weapon_refoLV, refineLV, earring_refoLV, bufferAttr, bufferAtk, sysBufferIdx, antiELE, guardELE;
    static MyGlobalShortCut *shortcut;
    static MyMouseHook *hook;
    static MainWindow *mw;
    static MessageWindow *messageWindow;
    static QVector<AttrData> vec;
    static void readfile();
    static void savefile();
    static bool setflag(const QString &key);
    static void sendMessage(const QString &str);
};

#endif // SETTINGDATA_H
