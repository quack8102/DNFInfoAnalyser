#include "equipment/h/coat_20.h"

void Coat_20::operator() (Character &model) {
        int lv = 100, qual = 0, type = 1;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addActiveLevelIN(1, 45, 1);
        model.addPassiveLevelIN(1, 45, 1);
    }

REGIST(Coat_20, QString::fromLocal8Bit("魔法师[???]的长袍"));
