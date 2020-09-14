#include "equipment/h/mage_3.h"

void Mage_3::operator() (Character &model) {
        int lv = 100, qual = 0, type = 5;
        int P_ATK = 1475, M_ATK = 1045, I_ATK = 770;
        int STR = 122, INT = 0;
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

REGIST(Mage_3, QObject::tr("歼灵灭魂矛"));
