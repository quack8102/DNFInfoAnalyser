#include "equipment/h/ring_12.h"

void Ring_12::operator() (Character &model) {
        int lv = 100, qual = 0, type = 10;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

        model.reformCnt++;
    }

REGIST(Ring_12, QObject::tr("骸麒之戒"));
