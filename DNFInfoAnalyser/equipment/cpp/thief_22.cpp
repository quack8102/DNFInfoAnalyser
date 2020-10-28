#include "equipment/h/thief_22.h"

void Thief_22::operator() (Character &model) { // 飘零之花手杖
    int P_ATK = 986, M_ATK = 1313, I_ATK = 711;
    int P_Growth = 184, M_Growth = 189;
    int STR = 0, INT = 81;
    if (model.isPhy) model.attr += STR;
    else model.attr += INT;
    if (model.isInd) model.atk += I_ATK + 115 * model.reformLV;
    else if (model.isPhy) model.atk += P_ATK + P_Growth * model.reformLV;
    else model.atk += M_ATK + M_Growth * model.reformLV;
    model.attr += 20 * model.reformLV;
}

REGIST(Thief_22, QString::fromLocal8Bit("飘零之花手杖"));
