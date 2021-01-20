#include "equipment/h/bracelet_24.h"

void Bracelet_24::operator() (Character &model) { // 无言怒火
    int lv = 100, qual = 0, type = 7;
    if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
    else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

    model.addAllElementIN(16 * model.reformLV);
    model.reformCnt++;
}

REGIST(Bracelet_24, QString::fromLocal8Bit("无言怒火"));