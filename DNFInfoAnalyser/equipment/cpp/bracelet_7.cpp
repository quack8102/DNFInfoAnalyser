#include "equipment/h/bracelet_7.h"

void Bracelet_7::operator() (Character &model) {
        int lv = 100, qual = 1, type = 7;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(32);
    }

REGIST(Bracelet_7, QString::fromLocal8Bit("狂乱之逆转宿命"));
