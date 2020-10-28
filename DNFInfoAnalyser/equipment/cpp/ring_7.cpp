#include "equipment/h/ring_7.h"

void Ring_7::operator() (Character &model) {
        int lv = 100, qual = 0, type = 10;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Ring_7, QString::fromLocal8Bit("蓬勃生命的落幕"));
