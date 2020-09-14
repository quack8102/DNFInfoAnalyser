#include "equipment/h/coat_37.h"

void Coat_37::operator() (Character &model) {
        int lv = 100, qual = 0, type = 1;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Coat_37, QObject::tr("泣血之恨"));
