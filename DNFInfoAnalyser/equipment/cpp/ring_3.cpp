﻿#include "equipment/h/ring_3.h"

void Ring_3::operator() (Character &model) {
        int lv = 100, qual = 0, type = 10;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(38);
    }

REGIST(Ring_3, QString::fromLocal8Bit("祝福之风-西尔芙"));
