#include "equipment/h/belt_24.h"

void Belt_24::operator() (Character &model) { // 无我之轮回
    int lv = 100, qual = 0, type = 3;
    if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
    else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
    model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
    model.reformCnt++;
}

REGIST(Belt_24, QObject::tr("无我之轮回"));
