#include "equipment/h/ring_5.h"

void Ring_5::operator() (Character &model) {
        int lv = 100, qual = 0, type = 10;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addActiveLevelIN(60, 80, 1);
        model.addPassiveLevelIN(60, 80, 1);
    }

REGIST(Ring_5, QObject::tr("次元穿越者之印"));
