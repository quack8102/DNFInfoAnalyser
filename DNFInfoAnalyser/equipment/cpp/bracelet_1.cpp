#include "equipment/h/bracelet_1.h"

void Bracelet_1::operator() (Character &model) {
        int lv = 100, qual = 1, type = 7;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(28);
        model.addActiveLevelIN(1, 48, 1);
        model.addPassiveLevelIN(1, 48, 1);

        int sumLv = 10 * model.ampLV + model.earring_refoLV;
        if (model.isInd) sumLv += model.ampLV;
        else sumLv += model.weapon_refoLV;
        if (sumLv > 150) sumLv = 150;
        sumLv /= 6;

        model.minCrt += 0.5 * sumLv;
        model.maxCrt += 0.5 * sumLv;

        model.atk += 110;
    }

REGIST(Bracelet_1, QString::fromLocal8Bit("融化黑暗之温暖"));
