#include "equipment/h/ring_1.h"

void Ring_1::operator() (Character &model) {
        int lv = 100, qual = 0, type = 10;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(30);
        model.addActiveLevelIN(75, 85, 1);
        model.addPassiveLevelIN(75, 85, 1);
    }

REGIST(Ring_1, QString::fromLocal8Bit("寂静无言之露珠"));
