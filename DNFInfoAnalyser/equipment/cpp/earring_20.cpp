#include "equipment/h/earring_20.h"

void Earring_20::operator() (Character &model) {
        int lv = 100, qual = 0, type = 11;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

        model.inatk += 40 * model.reformLV;
        if (model.reformLV >= 5) {
            model.addAllElementIN(40);
        }
        model.reformCnt++;
    }

REGIST(Earring_20, QString::fromLocal8Bit("窥视未来耳环"));
