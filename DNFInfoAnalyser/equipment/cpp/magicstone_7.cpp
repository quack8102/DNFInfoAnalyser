#include "equipment/h/magicstone_7.h"

void Magicstone_7::operator() (Character &model) {
        int lv = 100, qual = 0, type = 12;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
        model.attr += CALC::getRefoAttr(lv, qual, model.ampLV, type);
    }

REGIST(Magicstone_7, QString::fromLocal8Bit("狂乱之天灾降临"));
