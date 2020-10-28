#include "equipment/h/demoniclancer_12.h"

void Demoniclancer_12::operator() (Character &model) {
        int lv = 100, qual = -1, type = 5;
        int P_ATK = 1113, M_ATK = 1348, I_ATK = 719;
        int STR = 78, INT = 78;
        if (model.isInd) {
            if (model.isPhy) model.attr += STR;
            else model.attr += INT;
            model.atk += I_ATK;
            model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
            model.atk += CALC::getRefoAtk(lv, qual, model.refineLV, type, 1);
        } else {
            double wk = 0;
            if (model.isPhy) model.attr += STR, model.atk += P_ATK, wk = 1.095;
            else model.attr += INT, model.atk += M_ATK, wk = 1.115;
            model.atk += CALC::getRefoAtk(lv, qual, model.weapon_refoLV, type, wk);
        }
    }

REGIST(Demoniclancer_12, QString::fromLocal8Bit("暗黑圣战之溯回：光枪"));
