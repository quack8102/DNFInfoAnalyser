#include "equipment/h/bracelet_22.h"

void Bracelet_22::operator() (Character &model) {
        int lv = 100, qual = 0, type = 7;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

        model.addAllElementIN(8 * model.reformLV);
        model.reformCnt++;
    }

REGIST(Bracelet_22, QObject::tr("噙毒手套"));
