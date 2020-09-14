#include "equipment/h/shoes_13.h"

void Shoes_13::operator() (Character &model) {
        int lv = 100, qual = 0, type = 4;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Shoes_13, QObject::tr("守护的抉择"));
