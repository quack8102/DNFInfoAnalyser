#include "equipment/h/earring_0.h"

void Earring_0::operator() (Character &model) {
        int lv = 100, qual = 1, type = 11;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.atk += CALC::getRefoAtk(lv, qual, model.earring_refoLV, type);
    }

REGIST(Earring_0, QString::fromLocal8Bit("军神的心之所念"));
