#include "equipment/h/belt_11.h"

void Belt_11::operator() (Character &model) {
        int lv = 100, qual = 0, type = 3;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Belt_11, QObject::tr("千链锁灵腰带"));
