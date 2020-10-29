#include "character.h"
#include <QDebug>
#include "settingdata.h"

Character::Character() :
    classID(0), ampLV(0), weapon_refoLV(0), earring_refoLV(0),
    refineLV(0), reformLV(0), weaponType(0), armorType(0),
    isPhy(false), isInd(false), isHero(false), mode(false) {}

Character::Character(int id, int _attr, double crt, bool _isPhy, bool _isInd, int wType, int aType,
                     const QVector<int> &vec, const QSet<QString> &qs):
    classID(id), ampLV(SettingData::ampLV), weapon_refoLV(SettingData::weapon_refoLV), earring_refoLV(SettingData::earring_refoLV),
    refineLV(SettingData::refineLV), reformLV(SettingData::reformLV), weaponType(wType), armorType(aType),
    isPhy(_isPhy), isInd(_isInd), isHero(SettingData::isHero), mode(true),
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
    if (isInd) atk += 980;
    //qDebug() << "char: " << classID << " " << isPhy << " " << isInd << " " << attr << " " << atk << " " << minCrt << " " << FIRE_OUT << endl;
}

Character::Character(const Character &ch):
    classID(ch.classID), ampLV(SettingData::ampLV), weapon_refoLV(SettingData::weapon_refoLV), earring_refoLV(SettingData::earring_refoLV),
    refineLV(SettingData::refineLV), reformLV(SettingData::reformLV), weaponType(ch.weaponType), armorType(ch.armorType),
    isPhy(ch.isPhy), isInd(ch.isInd), isHero(SettingData::isHero), mode(false),
    activeLVOUT(ch.activeLVOUT), passiveLVOUT(ch.passiveLVOUT), activeLVIN(ch.activeLVIN), passiveLVIN(ch.passiveLVIN),
    equipName(ch.equipName), setCnt(ch.setCnt) {
    minCrt = maxCrt = 0;
    attr = atk = inatk = 0;
    FIRE_OUT = ICE_OUT = LIGHT_OUT = DARK_OUT = FIRE_IN = ICE_IN = LIGHT_IN = DARK_IN = 0;
    entryCnt = reformCnt = 0;
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
