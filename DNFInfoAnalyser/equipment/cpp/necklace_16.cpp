#include "equipment/h/necklace_16.h"

void Necklace_16::operator() (Character &model) {
        int lv = 100, qual = 0, type = 8;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

        if (model.setCnt->at(40) >= 5 && model.reformLV >= 1) {
            model.addAllElementIN(50);
            model.addActiveLevelIN(50, 50, 3);
            model.addActiveLevelIN(85, 85, 3);
            model.addActiveLevelIN(100, 100, 1);
            model.addPassiveLevelIN(50, 50, 3);
            model.addPassiveLevelIN(85, 85, 3);
            model.addPassiveLevelIN(100, 100, 1);
        }
        model.reformCnt++;
    }

REGIST(Necklace_16, QString::fromLocal8Bit("杀戮之决"));
