#include "equipment/h/ring_18.h"

void Ring_18::operator() (Character &model) { // 无念剑环
    int lv = 100, qual = 0, type = 10;
    if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
    else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

    if (model.reformLV >= 1) {
        model.addAllElementIN(40);
    }
    model.reformCnt++;
}

REGIST(Ring_18, QString::fromLocal8Bit("无念剑环"));