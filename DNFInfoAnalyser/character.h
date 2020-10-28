#ifndef CHARACTER_H
#define CHARACTER_H

#include <QVector>
#include <QSet>
#include <QString>
#include <memory>

class Character {
  public:
    const int classID, ampLV, weapon_refoLV, earring_refoLV, refineLV, reformLV, weaponType, armorType; // 1-布甲，2-皮甲，3-轻甲，4-重甲，5-板甲
    const bool isPhy, isInd, isHero, mode;
    int inatk, FIRE_OUT, ICE_OUT, LIGHT_OUT, DARK_OUT, FIRE_IN, ICE_IN, LIGHT_IN, DARK_IN, entryCnt, reformCnt;
    double attr, minCrt, maxCrt, atk;
    QVector<int> activeLVOUT, passiveLVOUT, activeLVIN, passiveLVIN;
    std::shared_ptr<QSet<QString> > equipName;
    std::shared_ptr<QVector<int> > setCnt;
    Character();
    Character(int id, int _attr, double crt, bool _isPhy, bool _isInd, int wType, int aType,
              const QVector<int> &vec, const QSet<QString> &qs);
    Character(const Character &ch);
    void addActiveLevelOUT(int l, int r, int c);
    void addPassiveLevelOUT(int l, int r, int c);
    void addActiveLevelIN(int l, int r, int c);
    void addPassiveLevelIN(int l, int r, int c);
    void addAllElementOUT(int c);
    void addAllElementIN(int c);
    void showDetail();
};

#endif // CHARACTER_H
