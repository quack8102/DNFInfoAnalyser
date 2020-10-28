#include "equipment/h/pants_9.h"

void Pants_9::operator() (Character &model) {
        int lv = 100, qual = 0, type = 2;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Pants_9, QString::fromLocal8Bit("亚蒙：谎言之力"));
