#include "equipment/h/gunner_4.h"

void Gunner_4::operator() (Character &model) {
        int lv = 100, qual = 0, type = 5;
        int P_ATK = 1238, M_ATK = 1042, I_ATK = 770;
        int STR = 81, INT = 0;
        if (model.isInd) {
            if (model.isPhy) model.attr += STR;
            else model.attr += INT;
            model.atk += I_ATK;
            model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
            model.atk += CALC::getRefoAtk(lv, qual, model.refineLV, type, 1);
        } else {
            double wk = 0;
            if (model.isPhy) model.attr += STR, model.atk += P_ATK, wk = 1.087;
            else model.attr += INT, model.atk += M_ATK, wk = 1.077;
            model.atk += CALC::getRefoAtk(lv, qual, model.weapon_refoLV, type, wk);
        }
    }

REGIST(Gunner_4, QString::fromLocal8Bit("血枪之脉"));
