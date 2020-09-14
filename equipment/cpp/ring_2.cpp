#include "equipment/h/ring_2.h"

void Ring_2::operator() (Character &model) {
        int lv = 100, qual = 0, type = 10;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Ring_2, QObject::tr("红兔之祝福"));
