#include "equipment/h/earring_21.h"

void Earring_21::operator() (Character &model) { // 无我灵晶
    int lv = 100, qual = 0, type = 11;
    if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
    else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

    model.reformCnt++;
}

REGIST(Earring_21, QString::fromLocal8Bit("无我灵晶"));