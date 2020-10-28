#include "equipment/h/bracelet_4.h"

void Bracelet_4::operator() (Character &model) {
        int lv = 100, qual = 1, type = 7;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementIN(40);
        model.attr += 240;
    }

REGIST(Bracelet_4, QString::fromLocal8Bit("无尽的探求"));
