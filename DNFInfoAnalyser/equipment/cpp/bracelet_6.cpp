#include "equipment/h/bracelet_6.h"

void Bracelet_6::operator() (Character &model) {
        int lv = 100, qual = 1, type = 7;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Bracelet_6, QString::fromLocal8Bit("响彻天地的咆哮"));
