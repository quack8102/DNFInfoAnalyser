#include "equipment/h/support_19.h"

void Support_19::operator() (Character &model) { // 支配者王冠
    int lv = 100, qual = 0, type = 9;
    if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
    else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

    model.reformCnt++;
}

REGIST(Support_19, QString::fromLocal8Bit("支配者王冠"));