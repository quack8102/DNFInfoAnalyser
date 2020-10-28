#include "equipment/h/coat_15.h"

void Coat_15::operator() (Character &model) {
        int lv = 100, qual = 1, type = 1;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addActiveLevelOUT(5, 100, 1);
        model.addPassiveLevelOUT(5, 100, 1);
        model.atk += 80;
    }

REGIST(Coat_15, QString::fromLocal8Bit("深渊囚禁者长袍"));
