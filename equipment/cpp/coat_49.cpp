#include "equipment/h/coat_49.h"

void Coat_49::operator() (Character &model) { // 无念之仪服
    int lv = 100, qual = 0, type = 1;
    if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
    else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
    model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);

    model.addActiveLevelIN(50, 50, 2);
    model.addActiveLevelIN(85, 85, 2);
    model.addActiveLevelIN(100, 100, 2);
    model.addPassiveLevelIN(50, 50, 2);
    model.addPassiveLevelIN(85, 85, 2);
    model.addPassiveLevelIN(100, 100, 2);
    model.reformCnt++;
}

REGIST(Coat_49, QObject::tr("无念之仪服"));
