#include "equipment/h/earring_17.h"

void Earring_17::operator() (Character &model) {
        int lv = 100, qual = -1, type = 11;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.atk += CALC::getRefoAtk(lv, qual, model.earring_refoLV, type);
    }

REGIST(Earring_17, QString::fromLocal8Bit("时空：腐蚀之黑色十字耳环"));
