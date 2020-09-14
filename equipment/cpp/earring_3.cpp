#include "equipment/h/earring_3.h"

void Earring_3::operator() (Character &model) {
        int lv = 100, qual = 1, type = 11;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.atk += CALC::getRefoAtk(lv, qual, model.earring_refoLV, type);

        if (model.equipName->contains(QObject::tr("电光能量支配者"))) {
            model.addAllElementIN(40);
        }
        model.attr += 220;
    }

REGIST(Earring_3, QObject::tr("等离子操控者"));
