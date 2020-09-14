#include "equipment/h/coat_38.h"

void Coat_38::operator() (Character &model) {
        int lv = 100, qual = -1, type = 1;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(22);
    }

REGIST(Coat_38, QObject::tr("黑暗幽灵紫杉胸甲"));
