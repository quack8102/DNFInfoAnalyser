#include "equipment/h/coat_33.h"

void Coat_33::operator() (Character &model) {
        int lv = 100, qual = 0, type = 1;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementIN(24);
    }

REGIST(Coat_33, QObject::tr("宽恕坚韧之地"));
