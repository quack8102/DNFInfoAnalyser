#include "equipment/h/magicstone_5.h"

void Magicstone_5::operator() (Character &model) {
        int lv = 100, qual = 0, type = 12;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
        model.attr += CALC::getRefoAttr(lv, qual, model.ampLV, type);

        model.addAllElementOUT(80);
    }

REGIST(Magicstone_5, QString::fromLocal8Bit("被困的时之沙"));
