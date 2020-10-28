#include "equipment/h/neck_7.h"

void Neck_7::operator() (Character &model) {
        int lv = 100, qual = 0, type = 0;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Neck_7, QString::fromLocal8Bit("炙炎：榴莲"));
