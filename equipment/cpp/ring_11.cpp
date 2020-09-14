#include "equipment/h/ring_11.h"

void Ring_11::operator() (Character &model) {
        int lv = 95, qual = 0, type = 10;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        if (model.equipName->contains(QObject::tr("江山如故"))) {
            model.attr += 100;
        }
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(16);
    }

REGIST(Ring_11, QObject::tr("碧水红潮"));
