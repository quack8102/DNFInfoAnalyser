#include "equipment/h/bracelet_3.h"

void Bracelet_3::operator() (Character &model) {
        int lv = 100, qual = 1, type = 7;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(38);
        model.attr += 160;
    }

REGIST(Bracelet_3, QObject::tr("至高之炎-伊弗利特"));
