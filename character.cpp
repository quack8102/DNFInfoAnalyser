#include "character.h"
#include <QDebug>

Character::Character() :
    classID(0), ampLV(0), weapon_refoLV(0), earring_refoLV(0),
    refineLV(0), reformLV(0), weaponType(0), armorType(0),
    isPhy(false), isInd(false), isHero(false) {}

Character::Character(int id, int _attr, double crt, bool _isPhy, bool _isInd, int wType, int aType,
                     const QVector<int> &vec, const QSet<QString> &qs, bool mode):
    classID(id), ampLV(mode ? 10 : 7), weapon_refoLV(12), earring_refoLV(mode ? 12 : 11),
    refineLV(8), reformLV(5), weaponType(wType), armorType(aType),
    isPhy(_isPhy), isInd(_isInd), isHero(true),
    activeLVOUT(101), passiveLVOUT(101), activeLVIN(101), passiveLVIN(101) {
    attr = _attr;
    minCrt = maxCrt = crt;
    atk = inatk = 0;
    FIRE_OUT = ICE_OUT = LIGHT_OUT = DARK_OUT = FIRE_IN = ICE_IN = LIGHT_IN = DARK_IN = 0;
    entryCnt = reformCnt = 0;
    equipName = std::make_shared<QSet<QString> >(qs);
    setCnt = std::make_shared<QVector<int> >(vec);
    attr += 275;
    atk += 65;
    addAllElementOUT(13);
    addActiveLevelOUT(1, 30, 1);
    addActiveLevelOUT(1, 50, 5);
    addPassiveLevelOUT(1, 50, 2);
    if (isInd) atk += 980;
    if (mode) {
        if (isPhy) attr += 1504;
        else attr += 1444;
        if (isInd) atk += 705;
        else atk += 695;
        addAllElementOUT(253);
        inatk += 60;
    } else {
        attr += 1156;
        atk += 447;
        addAllElementOUT(231);
        inatk += 40;
    }
    //qDebug() << "char: " << classID << " " << isPhy << " " << isInd << " " << attr << " " << atk << " " << minCrt << " " << FIRE_OUT << endl;
}

void Character::addActiveLevelOUT(int l, int r, int c) {
    for (int i = l; i <= r; ++i) activeLVOUT[i] += c;
}

void Character::addPassiveLevelOUT(int l, int r, int c) {
    for (int i = l; i <= r; ++i) passiveLVOUT[i] += c;
}

void Character::addActiveLevelIN(int l, int r, int c) {
    for (int i = l; i <= r; ++i) activeLVIN[i] += c;
}
void Character::addPassiveLevelIN(int l, int r, int c) {
    for (int i = l; i <= r; ++i) passiveLVIN[i] += c;
}

void Character::addAllElementOUT(int c) {
    FIRE_OUT += c;
    ICE_OUT += c;
    LIGHT_OUT += c;
    DARK_OUT += c;
}

void Character::addAllElementIN(int c) {
    FIRE_IN += c;
    ICE_IN += c;
    LIGHT_IN += c;
    DARK_IN += c;
}

void Character::showDetail() {
    qDebug() << "attr: " << int(attr) << ", atk: " << atk << ", entryCnt: " << entryCnt << ", reformCnt: " << reformCnt << endl;
    qDebug() << "FIRE_OUT: " << FIRE_OUT << ", ICE_OUT: " << ICE_OUT << ", LIGHT_OUT: " << LIGHT_OUT << ", DARK_OUT: " << DARK_OUT << endl;
    qDebug() << "inatk: " << inatk << ", minCrt: " << minCrt << ", maxCrt: " << maxCrt << endl;
    qDebug() << "FIRE_IN: " << FIRE_IN << ", ICE_IN: " << ICE_IN << ", LIGHT_IN: " << LIGHT_IN << ", DARK_IN: " << DARK_IN << endl;
}
