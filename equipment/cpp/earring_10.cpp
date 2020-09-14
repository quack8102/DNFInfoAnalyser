#include "equipment/h/earring_10.h"

void Earring_10::operator() (Character &model) {
        int lv = 100, qual = 0, type = 11;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.atk += CALC::getRefoAtk(lv, qual, model.earring_refoLV, type);
    }

REGIST(Earring_10, QObject::tr("时之矛盾"));
