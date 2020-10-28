#include "equipment/h/shoes_10.h"

void Shoes_10::operator() (Character &model) {
        int lv = 100, qual = 0, type = 4;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(70);
        model.addActiveLevelOUT(1, 85, 1);
        model.addActiveLevelOUT(100, 100, 1);
        model.addPassiveLevelOUT(1, 85, 1);
        model.addPassiveLevelOUT(100, 100, 1);
    }

REGIST(Shoes_10, QString::fromLocal8Bit("自然之核"));
