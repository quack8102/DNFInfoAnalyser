#include "equipment/h/shoes_16.h"

void Shoes_16::operator() (Character &model) {
        int lv = 100, qual = 0, type = 4;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addActiveLevelIN(1, 45, 1);
        model.addPassiveLevelIN(1, 45, 1);
    }

REGIST(Shoes_16, QString::fromLocal8Bit("次元漫步者长靴"));
