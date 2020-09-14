#include "equipment/h/demoniclancer_9.h"

void Demoniclancer_9::operator() (Character &model) {
        int lv = 100, qual = 0, type = 5;
        int P_ATK = 1475, M_ATK = 1045, I_ATK = 770;
        int STR = 81, INT = 0;
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
        model.addActiveLevelIN(1, 48, 2);
        model.addActiveLevelIN(55, 80, 2);
        model.addPassiveLevelIN(1, 48, 2);
        model.addPassiveLevelIN(55, 80, 2);
    }

REGIST(Demoniclancer_9, QObject::tr("沙岩幻戟"));
