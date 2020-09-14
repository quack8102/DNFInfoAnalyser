#include "equipment/h/neck_15.h"

void Neck_15::operator() (Character &model) {
        int lv = 100, qual = -1, type = 0;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(24);
    }

REGIST(Neck_15, QObject::tr("黑暗幽灵紫杉护肩"));
