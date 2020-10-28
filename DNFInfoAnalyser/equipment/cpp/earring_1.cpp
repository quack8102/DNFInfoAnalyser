#include "equipment/h/earring_1.h"

void Earring_1::operator() (Character &model) {
        int lv = 100, qual = 1, type = 11;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.atk += CALC::getRefoAtk(lv, qual, model.earring_refoLV, type);

        model.addAllElementIN(40);
        model.addAllElementOUT(40);
    }

REGIST(Earring_1, QString::fromLocal8Bit("永恒之海"));
