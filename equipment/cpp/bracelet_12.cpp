#include "equipment/h/bracelet_12.h"

void Bracelet_12::operator() (Character &model) {
        int lv = 100, qual = 0, type = 7;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementIN(40);
    }

REGIST(Bracelet_12, QObject::tr("执着的探求"));
