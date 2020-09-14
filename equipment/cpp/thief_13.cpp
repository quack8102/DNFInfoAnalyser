#include "equipment/h/thief_13.h"

void Thief_13::operator() (Character &model) {
        int lv = 100, qual = 0, type = 5;
        int P_ATK = 1086, M_ATK = 1414, I_ATK = 770;
        int STR = 0, INT = 81;
        if (model.isInd) {
            if (model.isPhy) model.attr += STR;
            else model.attr += INT;
            model.atk += I_ATK;
            model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
            model.atk += CALC::getRefoAtk(lv, qual, model.refineLV, type, 1);
        } else {
            double wk = 0;
            if (model.isPhy) model.attr += STR, model.atk += P_ATK, wk = 1.081;
            else model.attr += INT, model.atk += M_ATK, wk = 1.115;
            model.atk += CALC::getRefoAtk(lv, qual, model.weapon_refoLV, type, wk);
        }
    }

REGIST(Thief_13, QObject::tr("绿色生命的面容"));
