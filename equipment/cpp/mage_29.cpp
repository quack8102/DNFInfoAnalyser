#include "equipment/h/mage_29.h"

void Mage_29::operator() (Character &model) { // 飘零之花扫把
    int P_ATK = 1129, M_ATK = 1252, I_ATK = 711;
    int P_Growth = 187, M_Growth = 188;
    int STR = 0, INT = 81;
    if (model.isPhy) model.attr += STR;
    else model.attr += INT;
    if (model.isInd) model.atk += I_ATK + 115 * model.reformLV;
    else if (model.isPhy) model.atk += P_ATK + P_Growth * model.reformLV;
    else model.atk += M_ATK + M_Growth * model.reformLV;
    model.attr += 20 * model.reformLV;
}

REGIST(Mage_29, QObject::tr("飘零之花扫把"));
