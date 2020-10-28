#include "equipment/h/earring_13.h"

void Earring_13::operator() (Character &model) {
        int lv = 100, qual = 0, type = 11;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.atk += CALC::getRefoAtk(lv, qual, model.earring_refoLV, type);

        model.addActiveLevelIN(50, 50, 1);
        model.addActiveLevelIN(85, 85, 1);
        model.addActiveLevelIN(100, 100, 1);
        model.addPassiveLevelIN(50, 50, 1);
        model.addPassiveLevelIN(85, 85, 1);
        model.addPassiveLevelIN(100, 100, 1);
    }

REGIST(Earring_13, QString::fromLocal8Bit("次元流星坠"));
