#include "equipment/h/pants_14.h"

void Pants_14::operator() (Character &model) {
        int lv = 100, qual = 0, type = 2;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.DARK_IN += 24;
    }

REGIST(Pants_14, QString::fromLocal8Bit("蚕食新绿之息"));
