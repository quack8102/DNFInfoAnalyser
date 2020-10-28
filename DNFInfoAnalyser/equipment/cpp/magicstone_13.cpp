#include "equipment/h/magicstone_13.h"

void Magicstone_13::operator() (Character &model) {
        int lv = 100, qual = 0, type = 12;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

        if (model.setCnt->at(48) >= 3 && model.reformLV >= 4) {
            model.addAllElementIN(57);
            model.addActiveLevelIN(1, 85, 2);
            model.addActiveLevelIN(100, 100, 2);
            model.addPassiveLevelIN(1, 85, 2);
            model.addPassiveLevelIN(100, 100, 2);
        }
        model.reformCnt++;
    }

REGIST(Magicstone_13, QString::fromLocal8Bit("扭曲的异界魔石"));
