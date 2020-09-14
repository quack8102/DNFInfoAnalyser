#include "equipment/h/pants_8.h"

void Pants_8::operator() (Character &model) {
        int lv = 100, qual = 0, type = 2;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addActiveLevelOUT(35, 35, 2);
        model.addPassiveLevelOUT(35, 35, 2);
    }

REGIST(Pants_8, QObject::tr("雷霆万钧护腿"));
