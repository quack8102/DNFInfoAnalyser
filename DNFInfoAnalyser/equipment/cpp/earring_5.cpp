#include "equipment/h/earring_5.h"

void Earring_5::operator() (Character &model) {
        int lv = 100, qual = 1, type = 11;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.atk += CALC::getRefoAtk(lv, qual, model.earring_refoLV, type);

        model.addActiveLevelIN(50, 50, 1);
        model.addActiveLevelIN(85, 85, 1);
        model.addActiveLevelIN(100, 100, 1);
        model.addActiveLevelOUT(60, 100, 1);
        model.addPassiveLevelIN(50, 50, 1);
        model.addPassiveLevelIN(85, 85, 1);
        model.addPassiveLevelIN(100, 100, 1);
        model.addPassiveLevelOUT(60, 100, 1);
        model.attr += 300;
    }

REGIST(Earring_5, QString::fromLocal8Bit("次元穿越者之星"));
