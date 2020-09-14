#include "equipment/h/coat_8.h"

void Coat_8::operator() (Character &model) {
        int lv = 100, qual = 1, type = 1;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addActiveLevelOUT(45, 45, 2);
        model.addPassiveLevelOUT(45, 45, 2);
    }

REGIST(Coat_8, QObject::tr("摧枯拉朽胸甲"));
