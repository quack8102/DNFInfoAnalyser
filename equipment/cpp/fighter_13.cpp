#include "equipment/h/fighter_13.h"

void Fighter_13::operator() (Character &model) {
        int lv = 100, qual = 0, type = 5;
        int P_ATK = 1229, M_ATK = 1229, I_ATK = 770;
        int STR = 81, INT = 41;
        if (model.isInd) {
            if (model.isPhy) model.attr += STR;
            else model.attr += INT;
            model.atk += I_ATK;
            model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
            model.atk += CALC::getRefoAtk(lv, qual, model.refineLV, type, 1);
        } else {
            double wk = 0;
            if (model.isPhy) model.attr += STR, model.atk += P_ATK, wk = 1.1;
            else model.attr += INT, model.atk += M_ATK, wk = 1.1;
            model.atk += CALC::getRefoAtk(lv, qual, model.weapon_refoLV, type, wk);
        }
        if (model.classID == 11 || model.classID == 15) {
            model.addPassiveLevelOUT(25, 25, 3);
            model.addActiveLevelOUT(85, 85, 1);
        }
    }

REGIST(Fighter_13, QObject::tr("疯狂飓风"));
