#include "equipment/h/support_6.h"

void Support_6::operator() (Character &model) {
        int lv = 100, qual = 0, type = 9;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
        model.attr += CALC::getRefoAttr(lv, qual, model.ampLV, type);
    }

REGIST(Support_6, QString::fromLocal8Bit("悲情者遗物"));
