#include "equipment/h/necklace_18.h"

void Necklace_18::operator() (Character &model) { // 无形青岩
    int lv = 100, qual = 0, type = 8;
    if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
    else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

    model.reformCnt++;
}

REGIST(Necklace_18, QString::fromLocal8Bit("无形青岩"));