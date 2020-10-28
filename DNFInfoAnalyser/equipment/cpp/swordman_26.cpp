#include "equipment/h/swordman_26.h"

void Swordman_26::operator() (Character &model) { // 飘零之花太刀
    int P_ATK = 1067, M_ATK = 1190, I_ATK = 711;
    int P_Growth = 186, M_Growth = 187;
    int STR = 81, INT = 122;
    if (model.isPhy) model.attr += STR;
    else model.attr += INT;
    if (model.isInd) model.atk += I_ATK + 115 * model.reformLV;
    else {
        if (model.classID == 4) model.atk += M_ATK + M_Growth * model.reformLV;
        else {
            if (model.isPhy) model.atk += P_ATK + P_Growth * model.reformLV;
            else model.atk += M_ATK + M_Growth * model.reformLV;
        }
    }
    model.attr += 20 * model.reformLV;
}

REGIST(Swordman_26, QString::fromLocal8Bit("飘零之花太刀"));
