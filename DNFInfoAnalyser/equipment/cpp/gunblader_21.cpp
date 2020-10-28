#include "equipment/h/gunblader_21.h"

void Gunblader_21::operator() (Character &model) { // 飘零之花小太刀
    int P_ATK = 1129, M_ATK = 1129, I_ATK = 711;
    int P_Growth = 187, M_Growth = 187;
    int STR = 81, INT = 41;
    if (model.isPhy) model.attr += STR;
    else model.attr += INT;
    if (model.isInd) model.atk += I_ATK + 115 * model.reformLV;
    else if (model.isPhy) model.atk += P_ATK + P_Growth * model.reformLV;
    else model.atk += M_ATK + M_Growth * model.reformLV;
    model.attr += 20 * model.reformLV;
}

REGIST(Gunblader_21, QString::fromLocal8Bit("飘零之花小太刀"));
