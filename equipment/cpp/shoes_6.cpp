#include "equipment/h/shoes_6.h"

void Shoes_6::operator() (Character &model) {
        int lv = 100, qual = 0, type = 4;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Shoes_6, QObject::tr("寂静寒夜之忍耐"));
