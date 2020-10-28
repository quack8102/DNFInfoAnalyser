#include "equipment/h/coat_39.h"

void Coat_39::operator() (Character &model) {
        int lv = 100, qual = -1, type = 1;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Coat_39, QString::fromLocal8Bit("时空：黑暗幽灵紫杉胸甲"));
