﻿#include "equipment/h/gunner_19.h"

void Gunner_19::operator() (Character &model) {
        int lv = 100, qual = 0, type = 5;
        int P_ATK = 1447, M_ATK = 868, I_ATK = 770;
        int STR = 122, INT = 0;
        if (model.isInd) {
            if (model.isPhy) model.attr += STR;
            else model.attr += INT;
            model.atk += I_ATK;
            model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
            model.atk += CALC::getRefoAtk(lv, qual, model.refineLV, type, 1);
        } else {
            double wk = 0;
            if (model.isPhy) model.attr += STR, model.atk += P_ATK, wk = 1.106;
            else model.attr += INT, model.atk += M_ATK, wk = 1.064;
            model.atk += CALC::getRefoAtk(lv, qual, model.weapon_refoLV, type, wk);
        }

        model.addAllElementOUT(40);
        if (model.classID == 18 || model.classID == 22) {
            model.addActiveLevelOUT(50, 50, 2);
            model.addActiveLevelOUT(85, 85, 2);
            model.addActiveLevelOUT(100, 100, 2);
            model.addPassiveLevelOUT(50, 50, 2);
            model.addPassiveLevelOUT(85, 85, 2);
            model.addPassiveLevelOUT(100, 100, 2);
        }
    }

REGIST(Gunner_19, QString::fromLocal8Bit("绝杀：无人生还"));
