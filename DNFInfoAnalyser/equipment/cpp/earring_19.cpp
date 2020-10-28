#include "equipment/h/earring_19.h"

void Earring_19::operator() (Character &model) {
        int lv = 95, qual = 0, type = 11;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        if (model.equipName->contains(QString::fromLocal8Bit("天衍万物"))) {
            model.attr += 100;
        }
        model.atk += CALC::getRefoAtk(lv, qual, model.earring_refoLV, type);
    }

REGIST(Earring_19, QString::fromLocal8Bit("转世：回溯的生命"));
