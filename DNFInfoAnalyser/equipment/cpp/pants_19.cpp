#include "equipment/h/pants_19.h"

void Pants_19::operator() (Character &model) {
        int lv = 100, qual = -1, type = 2;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(22);
    }

REGIST(Pants_19, QString::fromLocal8Bit("黑暗幽灵紫杉护腿"));
