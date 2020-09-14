#include "equipment/h/swordman_5.h"

void Swordman_5::operator() (Character &model) {
        int lv = 95, qual = 0, type = 5;
        int P_ATK = 1112, M_ATK = 1230, I_ATK = 723;
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

REGIST(Swordman_5, QObject::tr("夜语黑瞳太刀"));
