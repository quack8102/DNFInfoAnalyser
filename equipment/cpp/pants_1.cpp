#include "equipment/h/pants_1.h"

void Pants_1::operator() (Character &model) {
        int lv = 100, qual = 0, type = 2;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementIN(18);
    }

REGIST(Pants_1, QObject::tr("魔法师[???]的护腿"));
