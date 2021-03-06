﻿#include "equipment/h/demoniclancer_4.h"

void Demoniclancer_4::operator() (Character &model) {
        int lv = 100, qual = 0, type = 5;
        int P_ATK = 1290, M_ATK = 1106, I_ATK = 770;
        int STR = 122, INT = 0;
        if (model.isInd) {
            if (model.isPhy) model.attr += STR;
            else model.attr += INT;
            model.atk += I_ATK;
            model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
            model.atk += CALC::getRefoAtk(lv, qual, model.refineLV, type, 1);
        } else {
            double wk = 0;
            if (model.isPhy) model.attr += STR, model.atk += P_ATK, wk = 1.105;
            else model.attr += INT, model.atk += M_ATK, wk = 1.09;
            model.atk += CALC::getRefoAtk(lv, qual, model.weapon_refoLV, type, wk);
        }
    }

REGIST(Demoniclancer_4, QString::fromLocal8Bit("彪悍冲锋者"));
