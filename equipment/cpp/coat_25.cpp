#include "equipment/h/coat_25.h"

void Coat_25::operator() (Character &model) {
        int lv = 100, qual = 0, type = 1;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Coat_25, QObject::tr("燃烧烈焰之勇气"));
