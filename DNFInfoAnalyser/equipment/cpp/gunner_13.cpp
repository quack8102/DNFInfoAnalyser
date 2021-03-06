﻿#include "equipment/h/gunner_13.h"

void Gunner_13::operator() (Character &model) {
        int lv = 100, qual = 0, type = 5;
        int P_ATK = 1331, M_ATK = 1157, I_ATK = 770;
        int STR = 81, INT = 122;
        if (model.isInd) {
            if (model.isPhy) model.attr += STR;
            else model.attr += INT;
            model.atk += I_ATK;
            model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
            model.atk += CALC::getRefoAtk(lv, qual, model.refineLV, type, 1);
        } else {
            double wk = 0;
            if (model.isPhy) model.attr += STR, model.atk += P_ATK, wk = 1.1;
            else model.attr += INT, model.atk += M_ATK, wk = 1.085;
            model.atk += CALC::getRefoAtk(lv, qual, model.weapon_refoLV, type, wk);
        }
    }

REGIST(Gunner_13, QString::fromLocal8Bit("湍流"));
