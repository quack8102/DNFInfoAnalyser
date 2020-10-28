#include "equipment/h/bracelet_8.h"

void Bracelet_8::operator() (Character &model) {
        int lv = 100, qual = 0, type = 7;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(25);
    }

REGIST(Bracelet_8, QString::fromLocal8Bit("莱多：变幻的规律"));
