#include "equipment/h/belt_9.h"

void Belt_9::operator() (Character &model) {
        int lv = 100, qual = 0, type = 3;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Belt_9, QObject::tr("亚巴顿：绝望地狱"));
