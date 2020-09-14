#include "equipment/h/earring_9.h"

void Earring_9::operator() (Character &model) {
        int lv = 100, qual = 0, type = 11;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.atk += CALC::getRefoAtk(lv, qual, model.earring_refoLV, type);

        model.addAllElementIN(40);
    }

REGIST(Earring_9, QObject::tr("宽容之海"));
