#include "equipment/h/neck_24.h"

void Neck_24::operator() (Character &model) {
        int lv = 100, qual = 0, type = 0;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);

        model.addActiveLevelIN(1, 85, 1);
        model.addActiveLevelIN(100, 100, 1);
        model.addPassiveLevelIN(1, 85, 1);
        model.addPassiveLevelIN(100, 100, 1);

        if (model.reformLV >= 1)
            model.addAllElementIN(20 * model.reformLV);
        model.reformCnt++;
    }

REGIST(Neck_24, QString::fromLocal8Bit("完美掌控"));
