#include "equipment/h/magicstone_10.h"

void Magicstone_10::operator() (Character &model) {
        int lv = 100, qual = 0, type = 12;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

        model.reformCnt++;
    }

REGIST(Magicstone_10, QObject::tr("赤鬼的次元石"));
