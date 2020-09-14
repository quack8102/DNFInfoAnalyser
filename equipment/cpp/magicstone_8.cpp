#include "equipment/h/magicstone_8.h"

void Magicstone_8::operator() (Character &model) {
        int lv = 100, qual = -1, type = 12;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
        model.attr += CALC::getRefoAttr(lv, qual, model.ampLV, type);
    }

REGIST(Magicstone_8, QObject::tr("腐蚀之黑色尖角"));
