#ifndef SETTINGDATA_H
#define SETTINGDATA_H

#include <QString>
#include <QVector>
#include <MyGlobalShortCut/MyGlobalShortCut.h>
#include "mainwindow.h"
#include "character.h"

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
    static bool isHotkey, isAutoSave, isHero, isBuffer;
    static int ampLV, reformLV, weapon_refoLV, refineLV, earring_refoLV, bufferAttr, bufferAtk, sysBufferIdx, antiELE, guardELE;
    static MyGlobalShortCut *shortcut;
    static MainWindow *mw;
    static QVector<AttrData> vec;
    static void readfile();
    static void savefile();
};

#endif // SETTINGDATA_H
