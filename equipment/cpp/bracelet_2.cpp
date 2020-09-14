#include "equipment/h/bracelet_2.h"

void Bracelet_2::operator() (Character &model) {
        int lv = 100, qual = 1, type = 7;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Bracelet_2, QObject::tr("伽内什的永恒庇护"));
