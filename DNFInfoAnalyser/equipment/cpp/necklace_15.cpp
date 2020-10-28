#include "equipment/h/necklace_15.h"

void Necklace_15::operator() (Character &model) {
        int lv = 100, qual = 0, type = 8;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

        if (model.setCnt->at(41) >= 5 && model.reformLV >= 3) {
            model.addAllElementIN(50);
        }
        model.reformCnt++;
    }

REGIST(Necklace_15, QString::fromLocal8Bit("天御万物"));
