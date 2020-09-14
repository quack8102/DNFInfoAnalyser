#include "equipment/h/necklace_12.h"

void Necklace_12::operator() (Character &model) {
        int lv = 100, qual = 0, type = 8;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

        model.reformCnt++;
    }

REGIST(Necklace_12, QObject::tr("先知者的预言"));
