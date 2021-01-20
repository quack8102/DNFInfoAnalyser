#include "equipment/h/magicstone_14.h"

void Magicstone_14::operator() (Character &model) { // 灵魂掠夺者
    int lv = 100, qual = 0, type = 12;
    if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
    else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

    model.reformCnt++;
}

REGIST(Magicstone_14, QString::fromLocal8Bit("灵魂掠夺者"));