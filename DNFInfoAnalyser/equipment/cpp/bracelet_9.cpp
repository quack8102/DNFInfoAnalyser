#include "equipment/h/bracelet_9.h"

void Bracelet_9::operator() (Character &model) {
        int lv = 100, qual = 0, type = 7;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(28);
        model.addActiveLevelIN(1, 48, 1);
        model.addPassiveLevelIN(1, 48, 1);
    }

REGIST(Bracelet_9, QString::fromLocal8Bit("拥抱晨曦之温暖"));
