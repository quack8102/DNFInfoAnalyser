#include "equipment/h/priest_3.h"

void Priest_3::operator() (Character &model) {
        int lv = 100, qual = 0, type = 5;
        int P_ATK = 1229, M_ATK = 1167, I_ATK = 770;
        int STR = 0, INT = 81;
        if (model.isInd) {
            if (model.isPhy) model.attr += STR;
            else model.attr += INT;
            model.atk += I_ATK;
            model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
            model.atk += CALC::getRefoAtk(lv, qual, model.refineLV, type, 1);
        } else {
            double wk = 0;
            if (model.isPhy) model.attr += STR, model.atk += P_ATK, wk = 1.1;
            else model.attr += INT, model.atk += M_ATK, wk = 1.095;
            model.atk += CALC::getRefoAtk(lv, qual, model.weapon_refoLV, type, wk);
        }

        model.minCrt += 8;
        model.maxCrt += 8;
    }

REGIST(Priest_3, QObject::tr("圣者的慈悲"));
