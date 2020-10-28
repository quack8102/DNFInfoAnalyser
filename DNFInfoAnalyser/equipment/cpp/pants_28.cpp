#include "equipment/h/pants_28.h"

void Pants_28::operator() (Character &model) { // 无形之气韵
    int lv = 100, qual = 0, type = 2;
    if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
    else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
    model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);

    if (model.reformLV >= 1) {
        model.addAllElementIN(30);
        model.addActiveLevelIN(50, 85, 1);
        model.addActiveLevelIN(100, 100, 1);
        model.addPassiveLevelIN(50, 85, 1);
        model.addPassiveLevelIN(100, 100, 1);
    }
    model.reformCnt++;
}

REGIST(Pants_28, QString::fromLocal8Bit("无形之气韵"));
