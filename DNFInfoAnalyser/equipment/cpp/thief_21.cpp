#include "equipment/h/thief_21.h"

void Thief_21::operator() (Character &model) { // 飘零之花双剑
    int P_ATK = 1243, M_ATK = 883, I_ATK = 711;
    int P_Growth = 187, M_Growth = 184;
    int STR = 81, INT = 0;
    if (model.isPhy) model.attr += STR;
    else model.attr += INT;
    if (model.isInd) model.atk += I_ATK + 115 * model.reformLV;
    else if (model.isPhy) model.atk += P_ATK + P_Growth * model.reformLV;
    else model.atk += M_ATK + M_Growth * model.reformLV;
    model.attr += 20 * model.reformLV;
}

REGIST(Thief_21, QString::fromLocal8Bit("飘零之花双剑"));
