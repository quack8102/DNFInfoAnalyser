﻿#include "equipment/h/gunblader_1.h"

void Gunblader_1::operator() (Character &model) {
        int lv = 95, qual = 0, type = 5;
        int P_ATK = 1265, M_ATK = 1054, I_ATK = 723;
        int STR = 78, INT = 78;
        if (model.isInd) {
            if (model.isPhy) model.attr += STR;
            else model.attr += INT;
            model.atk += I_ATK;
            model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
            model.atk += CALC::getRefoAtk(lv, qual, model.refineLV, type, 1);
        } else {
            double wk = 0;
            if (model.isPhy) model.attr += STR, model.atk += P_ATK, wk = 1.108;
            else model.attr += INT, model.atk += M_ATK, wk = 1.09;
            model.atk += CALC::getRefoAtk(lv, qual, model.weapon_refoLV, type, wk);
        }
    }

REGIST(Gunblader_1, QString::fromLocal8Bit("界·夜语黑瞳长刀"));
