#include "equipment/h/magicstone_12.h"

void Magicstone_12::operator() (Character &model) {
        int lv = 100, qual = 0, type = 12;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

        model.reformCnt++;
    }

REGIST(Magicstone_12, QObject::tr("冰雪公主的结晶"));
