#include "equipment/h/coat_27.h"

void Coat_27::operator() (Character &model) {
        int lv = 100, qual = 0, type = 1;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addActiveLevelOUT(45, 45, 2);
        model.addPassiveLevelOUT(45, 45, 2);
    }

REGIST(Coat_27, QString::fromLocal8Bit("气吞山河战甲"));
