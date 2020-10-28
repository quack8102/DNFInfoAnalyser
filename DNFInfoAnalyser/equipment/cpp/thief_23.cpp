#include "equipment/h/thief_23.h"

void Thief_23::operator() (Character &model) { // 飘零之花苦无
    int P_ATK = 928, M_ATK = 1252, I_ATK = 711;
    int P_Growth = 185, M_Growth = 188;
    int STR = 0, INT = 122;
    if (model.isPhy) model.attr += STR;
    else model.attr += INT;
    if (model.isInd) model.atk += I_ATK + 115 * model.reformLV;
    else if (model.isPhy) model.atk += P_ATK + P_Growth * model.reformLV;
    else model.atk += M_ATK + M_Growth * model.reformLV;
    model.attr += 20 * model.reformLV;
}

REGIST(Thief_23, QString::fromLocal8Bit("飘零之花苦无"));
