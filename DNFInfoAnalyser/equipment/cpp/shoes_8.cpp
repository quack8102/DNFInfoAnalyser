#include "equipment/h/shoes_8.h"

void Shoes_8::operator() (Character &model) {
        int lv = 100, qual = 0, type = 4;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addActiveLevelOUT(70, 70, 2);
        model.addPassiveLevelOUT(70, 70, 2);
    }

REGIST(Shoes_8, QString::fromLocal8Bit("遮天蔽日长靴"));
