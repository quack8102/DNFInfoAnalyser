#include "equipment/h/shoes_15.h"

void Shoes_15::operator() (Character &model) {
        int lv = 100, qual = 0, type = 4;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementIN(70);
        model.addActiveLevelIN(1, 90, 1);
        model.addActiveLevelIN(100, 100, 1);
        model.addPassiveLevelIN(1, 90, 1);
        model.addPassiveLevelIN(100, 100, 1);
    }

REGIST(Shoes_15, QString::fromLocal8Bit("堕入地狱之脚"));
