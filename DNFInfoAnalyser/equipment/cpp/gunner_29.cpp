#include "equipment/h/gunner_29.h"

void Gunner_29::operator() (Character &model) { // 飘零之花手弩
    int P_ATK = 942, M_ATK = 1057, I_ATK = 711;
    int P_Growth = 183, M_Growth = 184;
    int STR = 81, INT = 41;
    if (model.isPhy) model.attr += STR;
    else model.attr += INT;
    if (model.isInd) model.atk += I_ATK + 115 * model.reformLV;
    else if (model.isPhy) model.atk += P_ATK + P_Growth * model.reformLV;
    else model.atk += M_ATK + M_Growth * model.reformLV;
    model.attr += 20 * model.reformLV;
}

REGIST(Gunner_29, QString::fromLocal8Bit("飘零之花手弩"));
