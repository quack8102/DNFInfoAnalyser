#include "equipment/h/earring_11.h"

void Earring_11::operator() (Character &model) {
        int lv = 100, qual = 0, type = 11;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.atk += CALC::getRefoAtk(lv, qual, model.earring_refoLV, type);

        if (model.equipName->contains(QString::fromLocal8Bit("电光能量支配者"))) {
            model.addAllElementIN(40);
        }
    }

REGIST(Earring_11, QString::fromLocal8Bit("电磁能量传送者"));
