#include "equipment/h/earring_14.h"

void Earring_14::operator() (Character &model) {
        int lv = 100, qual = 0, type = 11;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.atk += CALC::getRefoAtk(lv, qual, model.earring_refoLV, type);
    }

REGIST(Earring_14, QString::fromLocal8Bit("命运挑战者"));
