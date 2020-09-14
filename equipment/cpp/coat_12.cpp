#include "equipment/h/coat_12.h"

void Coat_12::operator() (Character &model) {
        int lv = 100, qual = 1, type = 1;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addActiveLevelOUT(25, 45, 1);
        model.addPassiveLevelOUT(25, 45, 1);
    }

REGIST(Coat_12, QObject::tr("英明循环之生命"));
