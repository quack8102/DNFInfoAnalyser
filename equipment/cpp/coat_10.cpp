#include "equipment/h/coat_10.h"

void Coat_10::operator() (Character &model) {
        int lv = 100, qual = 1, type = 1;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Coat_10, QObject::tr("天堂之翼"));
