﻿#include "equipment/h/necklace_3.h"

void Necklace_3::operator() (Character &model) {
        int lv = 100, qual = 0, type = 8;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(38);
    }

REGIST(Necklace_3, QString::fromLocal8Bit("冷焰之冰-温蒂妮"));
