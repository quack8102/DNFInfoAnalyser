#include "equipment/h/neck_8.h"

void Neck_8::operator() (Character &model) {
        int lv = 100, qual = 0, type = 0;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addActiveLevelOUT(60, 60, 2);
        model.addPassiveLevelOUT(60, 60, 2);
    }

REGIST(Neck_8, QString::fromLocal8Bit("排山倒海护肩"));
