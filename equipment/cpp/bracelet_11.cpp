#include "equipment/h/bracelet_11.h"

void Bracelet_11::operator() (Character &model) {
        int lv = 100, qual = 0, type = 7;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(38);
    }

REGIST(Bracelet_11, QObject::tr("火魔之焰-沙罗曼达"));
