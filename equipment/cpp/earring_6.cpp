#include "equipment/h/earring_6.h"

void Earring_6::operator() (Character &model) {
        int lv = 100, qual = 1, type = 11;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.atk += CALC::getRefoAtk(lv, qual, model.earring_refoLV, type);

        model.atk += 120;
        model.addActiveLevelOUT(25, 45, 1);
        model.addPassiveLevelOUT(25, 45, 1);
    }

REGIST(Earring_6, QObject::tr("命运反抗者"));
