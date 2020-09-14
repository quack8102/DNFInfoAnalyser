#include "equipment/h/earring_7.h"

void Earring_7::operator() (Character &model) {
        int lv = 100, qual = 1, type = 11;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.atk += CALC::getRefoAtk(lv, qual, model.earring_refoLV, type);

        model.addAllElementOUT(16);
        model.attr += 140;
    }

REGIST(Earring_7, QObject::tr("心痛如绞的诀别"));
