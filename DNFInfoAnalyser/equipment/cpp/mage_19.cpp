#include "equipment/h/mage_19.h"

void Mage_19::operator() (Character &model) {
        int lv = 100, qual = 0, type = 5;
        int P_ATK = 1167, M_ATK = 1475, I_ATK = 770;
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
            else model.attr += INT, model.atk += M_ATK, wk = 1.12;
            model.atk += CALC::getRefoAtk(lv, qual, model.weapon_refoLV, type, wk);
        }

        if (!model.isPhy) {
            model.minCrt += 5;
            model.maxCrt += 5;
        }

        model.addActiveLevelIN(50, 50, 2);
        model.addActiveLevelIN(85, 85, 2);
        model.addActiveLevelIN(100, 100, 2);
        model.addPassiveLevelIN(50, 50, 2);
        model.addPassiveLevelIN(85, 85, 2);
        model.addPassiveLevelIN(100, 100, 2);
    }

REGIST(Mage_19, QString::fromLocal8Bit("银月的祝福"));
