#include "equipment/h/neck_25.h"

void Neck_25::operator() (Character &model) { // 无欲之花
    int lv = 100, qual = 0, type = 0;
    if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
    else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
    model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
    model.reformCnt++;
}

REGIST(Neck_25, QString::fromLocal8Bit("无欲之花"));
