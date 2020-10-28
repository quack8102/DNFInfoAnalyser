#include "equipment/h/necklace_13.h"

void Necklace_13::operator() (Character &model) {
        int lv = 100, qual = 0, type = 8;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

        if (model.setCnt->at(46) >= 5 && model.reformLV >= 1) {
            model.addAllElementIN(50);
            model.addActiveLevelIN(50, 85, 2);
            model.addActiveLevelIN(100, 100, 2);
            model.addPassiveLevelIN(50, 85, 2);
            model.addPassiveLevelIN(100, 100, 2);
        }
        model.reformCnt++;
    }

REGIST(Necklace_13, QString::fromLocal8Bit("全能霸域"));
