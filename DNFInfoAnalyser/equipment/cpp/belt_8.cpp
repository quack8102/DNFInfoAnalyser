#include "equipment/h/belt_8.h"

void Belt_8::operator() (Character &model) {
        int lv = 100, qual = 0, type = 3;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addActiveLevelOUT(40, 40, 2);
        model.addPassiveLevelOUT(40, 40, 2);
    }

REGIST(Belt_8, QString::fromLocal8Bit("风起云涌腰带"));
