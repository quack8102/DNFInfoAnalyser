#include "equipment/h/necklace_0.h"

void Necklace_0::operator() (Character &model) {
        int lv = 100, qual = 0, type = 8;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(25);
    }

REGIST(Necklace_0, QObject::tr("肯那兹：精神燎原之火"));
