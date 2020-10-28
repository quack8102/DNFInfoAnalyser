#include "equipment/h/pants_17.h"

void Pants_17::operator() (Character &model) {
        int lv = 100, qual = 0, type = 2;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Pants_17, QString::fromLocal8Bit("灵魂的呐喊"));
