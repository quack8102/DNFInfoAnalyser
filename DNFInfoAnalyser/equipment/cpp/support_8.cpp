﻿#include "equipment/h/support_8.h"

void Support_8::operator() (Character &model) {
        int lv = 100, qual = -1, type = 9;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
        model.attr += CALC::getRefoAttr(lv, qual, model.ampLV, type);
    }

REGIST(Support_8, QString::fromLocal8Bit("腐蚀之黑色面具"));
