#include "equipment/h/earring_16.h"

void Earring_16::operator() (Character &model) {
        int lv = 100, qual = -1, type = 11;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.atk += CALC::getRefoAtk(lv, qual, model.earring_refoLV, type);
    }

REGIST(Earring_16, QObject::tr("腐蚀之黑色十字耳环"));
