﻿#include "equipment/h/swordman_23.h"

void Swordman_23::operator() (Character &model) {
        int lv = 100, qual = 0, type = 5;
        int P_ATK = 1143, M_ATK = 1106, I_ATK = 770;
        int STR = 81, INT = 0;
        if (model.isInd) {
            if (model.isPhy) model.attr += STR;
            else model.attr += INT;
            model.atk += I_ATK;
            model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
            model.atk += CALC::getRefoAtk(lv, qual, model.refineLV, type, 1);
        } else {
            double wk = 0;
            if (model.isPhy) model.attr += STR, model.atk += P_ATK, wk = 1.093;
            else model.attr += INT, model.atk += M_ATK, wk = 1.09;
            model.atk += CALC::getRefoAtk(lv, qual, model.weapon_refoLV, type, wk);
        }

        model.addAllElementOUT(25);
    }

REGIST(Swordman_23, QString::fromLocal8Bit("星之海：巴德纳尔"));
