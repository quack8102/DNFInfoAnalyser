﻿#include "equipment/h/necklace_4.h"

void Necklace_4::operator() (Character &model) {
        int lv = 100, qual = 0, type = 8;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Necklace_4, QString::fromLocal8Bit("堕落世界树之生命"));
