#include "equipment/h/necklace_8.h"

void Necklace_8::operator() (Character &model) {
        int lv = 100, qual = -1, type = 8;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(28);
    }

REGIST(Necklace_8, QString::fromLocal8Bit("维度定位项链"));
