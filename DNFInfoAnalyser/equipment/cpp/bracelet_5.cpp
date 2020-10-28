#include "equipment/h/bracelet_5.h"

void Bracelet_5::operator() (Character &model) {
        int lv = 100, qual = 1, type = 7;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(20);
        model.atk += 100;
    }

REGIST(Bracelet_5, QString::fromLocal8Bit("时间回溯之针"));
