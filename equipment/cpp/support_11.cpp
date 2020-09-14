#include "equipment/h/support_11.h"

void Support_11::operator() (Character &model) {
        int lv = 100, qual = 0, type = 9;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

        model.reformCnt++;
    }

REGIST(Support_11, QObject::tr("聚魔漩涡"));
