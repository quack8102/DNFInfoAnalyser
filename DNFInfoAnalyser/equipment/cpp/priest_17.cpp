#include "equipment/h/priest_17.h"

void Priest_17::operator() (Character &model) {
        int lv = 100, qual = -1, type = 5;
        int P_ATK = 1113, M_ATK = 1172, I_ATK = 719;
        int STR = 78, INT = 78;
        if (model.isInd) {
            if (model.isPhy) model.attr += STR;
            else model.attr += INT;
            model.atk += I_ATK;
            model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
            model.atk += CALC::getRefoAtk(lv, qual, model.refineLV, type, 1);
        } else {
            double wk = 0;
            if (model.isPhy) model.attr += STR, model.atk += P_ATK, wk = 1.105;
            else model.attr += INT, model.atk += M_ATK, wk = 1.105;
            model.atk += CALC::getRefoAtk(lv, qual, model.weapon_refoLV, type, wk);
        }
    }

REGIST(Priest_17, QString::fromLocal8Bit("暗黑圣战之溯回：镰刀"));
