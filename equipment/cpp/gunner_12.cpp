#include "equipment/h/gunner_12.h"

void Gunner_12::operator() (Character &model) {
        int lv = 100, qual = -1, type = 5;
        int P_ATK = 1266, M_ATK = 1101, I_ATK = 719;
        int STR = 78, INT = 117;
        if (model.isInd) {
            if (model.isPhy) model.attr += STR;
            else model.attr += INT;
            model.atk += I_ATK;
            model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
            model.atk += CALC::getRefoAtk(lv, qual, model.refineLV, type, 1);
        } else {
            double wk = 0;
            if (model.isPhy) model.attr += STR, model.atk += P_ATK, wk = 1.1;
            else model.attr += INT, model.atk += M_ATK, wk = 1.085;
            model.atk += CALC::getRefoAtk(lv, qual, model.weapon_refoLV, type, wk);
        }
    }

REGIST(Gunner_12, QObject::tr("暗黑圣战之溯回：步枪"));
