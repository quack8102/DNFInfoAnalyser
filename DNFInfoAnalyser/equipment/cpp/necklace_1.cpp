#include "equipment/h/necklace_1.h"

void Necklace_1::operator() (Character &model) {
        int lv = 100, qual = 0, type = 8;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(28);
        model.addActiveLevelIN(50, 70, 1);
        model.addPassiveLevelIN(50, 70, 1);
    }

REGIST(Necklace_1, QString::fromLocal8Bit("驱散月光之黎明"));
