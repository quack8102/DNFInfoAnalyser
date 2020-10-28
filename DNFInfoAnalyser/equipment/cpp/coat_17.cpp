#include "equipment/h/coat_17.h"

void Coat_17::operator() (Character &model) {
        int lv = 100, qual = 1, type = 1;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addActiveLevelOUT(30, 48, 1);
        model.addPassiveLevelOUT(30, 48, 1);
        model.atk += 70;
        model.attr += 160;
    }

REGIST(Coat_17, QString::fromLocal8Bit("逆转结局"));
