#include "equipment/h/swordman_7.h"

void Swordman_7::operator() (Character &model) {
        int lv = 100, qual = -1, type = 5;
        int P_ATK = 1113, M_ATK = 1230, I_ATK = 719;
        int STR = 78, INT = 117;
        if (model.isInd) {
            if (model.isPhy) model.attr += STR;
            else model.attr += INT;
            model.atk += I_ATK;
            model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
            model.atk += CALC::getRefoAtk(lv, qual, model.refineLV, type, 1);
        } else {
            double wk = 0, p_wk = 1.095, m_wk = 1.105;
            if (model.classID == 4) {
                p_wk = m_wk;
                P_ATK = M_ATK;
            }
            if (model.isPhy) model.attr += STR, model.atk += P_ATK, wk = p_wk;
            else model.attr += INT, model.atk += M_ATK, wk = m_wk;
            model.atk += CALC::getRefoAtk(lv, qual, model.weapon_refoLV, type, wk);
        }
    }

REGIST(Swordman_7, QString::fromLocal8Bit("暗黑圣战之溯回：太刀"));
