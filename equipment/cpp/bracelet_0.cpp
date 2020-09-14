#include "equipment/h/bracelet_0.h"

void Bracelet_0::operator() (Character &model) {
        int lv = 100, qual = 1, type = 7;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(25);
    }

REGIST(Bracelet_0, QObject::tr("莱多：秩序创造者"));
