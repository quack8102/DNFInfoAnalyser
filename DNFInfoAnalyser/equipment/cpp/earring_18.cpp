#include "equipment/h/earring_18.h"

void Earring_18::operator() (Character &model) {
    int lv = 100, qual = 0, type = 11;
    if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
    else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

    model.reformCnt++;
    model.attr += 25 * model.reformLV;
}

REGIST(Earring_18, QString::fromLocal8Bit("轮回：腐蚀之黑色十字耳环"));
