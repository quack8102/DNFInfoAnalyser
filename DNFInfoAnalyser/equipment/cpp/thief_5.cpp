﻿#include "equipment/h/thief_5.h"

void Thief_5::operator() (Character &model) {
        int lv = 95, qual = 0, type = 5;
        int P_ATK = 1278, M_ATK = 937, I_ATK = 723;
        int STR = 78, INT = 0;
        if (model.isInd) {
            if (model.isPhy) model.attr += STR;
            else model.attr += INT;
            model.atk += I_ATK;
            model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
            model.atk += CALC::getRefoAtk(lv, qual, model.refineLV, type, 1);
        } else {
            double wk = 0;
            if (model.isPhy) model.attr += STR, model.atk += P_ATK, wk = 1.102;
            else model.attr += INT, model.atk += M_ATK, wk = 1.08;
            model.atk += CALC::getRefoAtk(lv, qual, model.weapon_refoLV, type, wk);
        }
    }

REGIST(Thief_5, QString::fromLocal8Bit("夜语黑瞳双剑"));
