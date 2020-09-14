#include "equipment/h/coat_1.h"

void Coat_1::operator() (Character &model) {
        int lv = 100, qual = 1, type = 1;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addActiveLevelOUT(1, 45, 1);
        model.addPassiveLevelOUT(1, 45, 1);
        model.addActiveLevelIN(1, 45, 1);
        model.addPassiveLevelIN(1, 45, 1);
    }

REGIST(Coat_1, QObject::tr("大魔法师[???]的长袍"));
