#include "equipment/h/bracelet_23.h"

void Bracelet_23::operator() (Character &model) {
        int lv = 100, qual = 0, type = 7;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

        if (model.setCnt->at(50) >= 3 && model.reformLV >= 4) {
            model.addAllElementIN(60);
        }
        model.reformCnt++;
    }

REGIST(Bracelet_23, QObject::tr("天衍万物"));
