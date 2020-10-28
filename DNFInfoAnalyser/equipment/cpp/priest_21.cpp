#include "equipment/h/priest_21.h"

void Priest_21::operator() (Character &model) {
        int lv = 95, qual = 0, type = 5;
        int P_ATK = 1406, M_ATK = 996, I_ATK = 723;
        int STR = 78, INT = 0;
        if (model.isInd) {
            if (model.isPhy) model.attr += STR;
            else model.attr += INT;
            model.atk += I_ATK;
            model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
            model.atk += CALC::getRefoAtk(lv, qual, model.refineLV, type, 1);
        } else {
            double wk = 0;
            if (model.isPhy) model.attr += STR, model.atk += P_ATK, wk = 1.12;
            else model.attr += INT, model.atk += M_ATK, wk = 1.085;
            model.atk += CALC::getRefoAtk(lv, qual, model.weapon_refoLV, type, wk);
        }
    }

REGIST(Priest_21, QString::fromLocal8Bit("界·夜语黑瞳战斧"));
