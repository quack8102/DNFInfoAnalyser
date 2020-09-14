#include "equipment/h/mage_1.h"

void Mage_1::operator() (Character &model) {
        int lv = 95, qual = 0, type = 5;
        int P_ATK = 1406, M_ATK = 996, I_ATK = 723;
        int STR = 117, INT = 0;
        if (model.isInd) {
            if (model.isPhy) model.attr += STR;
            else model.attr += INT;
            model.atk += I_ATK;
            model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
            model.atk += CALC::getRefoAtk(lv, qual, model.refineLV, type, 1);
        } else {
            double wk = 0, p_wk = 1.12, m_wk = 1.085;
            if (model.classID == 32) {
                M_ATK = P_ATK;
                m_wk = p_wk;
            }
            if (model.isPhy) model.attr += STR, model.atk += P_ATK, wk = p_wk;
            else model.attr += INT, model.atk += M_ATK, wk = m_wk;
            model.atk += CALC::getRefoAtk(lv, qual, model.weapon_refoLV, type, wk);
        }
    }

REGIST(Mage_1, QObject::tr("界·夜语黑瞳矛"));
