#include "equipment/h/thief_20.h"

void Thief_20::operator() (Character &model) { // 飘零之花匕首
    int P_ATK = 1067, M_ATK = 1005, I_ATK = 711;
    int P_Growth = 185, M_Growth = 185;
    int STR = 81, INT = 0;
    if (model.isPhy) model.attr += STR;
    else model.attr += INT;
    if (model.isInd) model.atk += I_ATK + 115 * model.reformLV;
    else if (model.isPhy) model.atk += P_ATK + P_Growth * model.reformLV;
    else model.atk += M_ATK + M_Growth * model.reformLV;
    model.attr += 20 * model.reformLV;
}

REGIST(Thief_20, QObject::tr("飘零之花匕首"));
