#include "equipment/h/mage_24.h"

void Mage_24::operator() (Character &model) {
        int lv = 100, qual = 0, type = 5;
        int P_ATK = 1229, M_ATK = 1352, I_ATK = 770;
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
            else model.attr += INT, model.atk += M_ATK, wk = 1.11;
            model.atk += CALC::getRefoAtk(lv, qual, model.weapon_refoLV, type, wk);
        }

        model.addAllElementIN(26);
    }

REGIST(Mage_24, QObject::tr("纯白的祈祷"));
