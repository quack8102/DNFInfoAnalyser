#include "equipment/h/necklace_17.h"

void Necklace_17::operator() (Character &model) {
        int lv = 100, qual = 0, type = 8;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

        if (model.setCnt->at(39) >= 5) {
            if (model.reformLV >= 3) {
                model.addAllElementIN(42);
            }
            if (model.reformLV >= 5) {
                model.addActiveLevelIN(1, 85, 2);
                model.addActiveLevelIN(100, 100, 2);
                model.addPassiveLevelIN(1, 85, 2);
                model.addPassiveLevelIN(100, 100, 2);
            }
        }
        model.reformCnt++;
    }

REGIST(Necklace_17, QString::fromLocal8Bit("逝魔之痕"));
