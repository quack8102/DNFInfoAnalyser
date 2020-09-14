#include "equipment/h/necklace_11.h"

void Necklace_11::operator() (Character &model) {
        int lv = 95, qual = 0, type = 8;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        if (model.equipName->contains(QObject::tr("江山如故"))) {
            model.attr += 100;
        }
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(16);
    }

REGIST(Necklace_11, QObject::tr("千寻一醉"));
