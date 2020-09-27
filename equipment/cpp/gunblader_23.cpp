#include "equipment/h/gunblader_23.h"

void Gunblader_23::operator() (Character &model) { // 飘零之花源力剑
    int P_ATK = 1067, M_ATK = 1313, I_ATK = 711;
    int P_Growth = 186, M_Growth = 189;
    int STR = 0, INT = 81;
    if (model.isPhy) model.attr += STR;
    else model.attr += INT;
    if (model.isInd) model.atk += I_ATK + 115 * model.reformLV;
    else if (model.isPhy) model.atk += P_ATK + P_Growth * model.reformLV;
    else model.atk += M_ATK + M_Growth * model.reformLV;
    model.attr += 20 * model.reformLV;
}

REGIST(Gunblader_23, QObject::tr("飘零之花源力剑"));
