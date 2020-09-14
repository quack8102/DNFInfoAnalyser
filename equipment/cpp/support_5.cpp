#include "equipment/h/support_5.h"

void Support_5::operator() (Character &model) {
        int lv = 100, qual = 0, type = 9;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
        model.attr += CALC::getRefoAttr(lv, qual, model.ampLV, type);

        model.addAllElementOUT(64);
    }

REGIST(Support_5, QObject::tr("引路者的旅行书"));
