#include "equipment/h/mage_28.h"

void Mage_28::operator() (Character &model) { // 飘零之花法杖
    int P_ATK = 1067, M_ATK = 1375, I_ATK = 711;
    int P_Growth = 186, M_Growth = 190;
    int STR = 0, INT = 81;
    if (model.isPhy) model.attr += STR;
    else model.attr += INT;
    if (model.isInd) model.atk += I_ATK + 115 * model.reformLV;
    else if (model.isPhy) model.atk += P_ATK + P_Growth * model.reformLV;
    else model.atk += M_ATK + M_Growth * model.reformLV;
    model.attr += 20 * model.reformLV;
}

REGIST(Mage_28, QObject::tr("飘零之花法杖"));
