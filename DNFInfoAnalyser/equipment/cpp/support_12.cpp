#include "equipment/h/support_12.h"

void Support_12::operator() (Character &model) {
        int lv = 100, qual = 0, type = 9;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

        model.reformCnt++;
    }

REGIST(Support_12, QString::fromLocal8Bit("禁断契约书"));
