#include "equipment/h/neck_1.h"

void Neck_1::operator() (Character &model) {
        int lv = 100, qual = 0, type = 0;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.maxCrt += 5;
        model.minCrt += 5;
    }

REGIST(Neck_1, QString::fromLocal8Bit("魔法师[???]的披风"));
