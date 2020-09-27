#include "equipment/h/priest_29.h"

void Priest_29::operator() (Character &model) { // 飘零之花战斧
    int P_ATK = 1375, M_ATK = 945, I_ATK = 711;
    int P_Growth = 190, M_Growth = 184;
    int STR = 81, INT = 0;
    if (model.isPhy) model.attr += STR;
    else model.attr += INT;
    if (model.isInd) model.atk += I_ATK + 115 * model.reformLV;
    else if (model.isPhy) model.atk += P_ATK + P_Growth * model.reformLV;
    else model.atk += M_ATK + M_Growth * model.reformLV;
    model.attr += 20 * model.reformLV;
}

REGIST(Priest_29, QObject::tr("飘零之花战斧"));
