﻿#include "equipment/h/priest_28.h"

void Priest_28::operator() (Character &model) { // 飘零之花镰刀
    int P_ATK = 1067, M_ATK = 1129, I_ATK = 711;
    int P_Growth = 187, M_Growth = 187;
    int STR = 81, INT = 81;
    if (model.isPhy) model.attr += STR;
    else model.attr += INT;
    if (model.isInd) model.atk += I_ATK + 115 * model.reformLV;
    else if (model.isPhy) model.atk += P_ATK + P_Growth * model.reformLV;
    else model.atk += M_ATK + M_Growth * model.reformLV;
    model.attr += 20 * model.reformLV;
}

REGIST(Priest_28, QString::fromLocal8Bit("飘零之花镰刀"));
