#include "equipment/h/bracelet_21.h"

void Bracelet_21::operator() (Character &model) {
        int lv = 95, qual = 0, type = 7;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        if (model.equipName->contains(QObject::tr("江山如故"))) {
            model.attr += 100;
        }
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(16);
    }

REGIST(Bracelet_21, QObject::tr("雪浪风尘"));
