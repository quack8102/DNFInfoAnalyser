﻿#include "equipment/h/fighter_4.h"

void Fighter_4::operator() (Character &model) {
        int lv = 100, qual = 0, type = 5;
        int P_ATK = 1167, M_ATK = 1414, I_ATK = 770;
        int STR = 0, INT = 81;
        if (model.isInd) {
            if (model.isPhy) model.attr += STR;
            else model.attr += INT;
            model.atk += I_ATK;
            model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
            model.atk += CALC::getRefoAtk(lv, qual, model.refineLV, type, 1);
        } else {
            double wk = 0;
            if (model.isPhy) model.attr += STR, model.atk += P_ATK, wk = 1.095;
            else model.attr += INT, model.atk += M_ATK, wk = 1.115;
            model.atk += CALC::getRefoAtk(lv, qual, model.weapon_refoLV, type, wk);
        }
        model.addActiveLevelOUT(1, 48, 2);
        model.addActiveLevelOUT(60, 80, 2);
        model.addPassiveLevelOUT(1, 48, 2);
        model.addPassiveLevelOUT(60, 80, 2);
    }

REGIST(Fighter_4, QString::fromLocal8Bit("无瑕之意志手套"));
