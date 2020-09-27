#include "equipment/h/gunner_28.h"

void Gunner_28::operator() (Character &model) { // 飘零之花手炮
    int P_ATK = 1346, M_ATK = 768, I_ATK = 711;
    int P_Growth = 188, M_Growth = 181;
    int STR = 122, INT = 0;
    if (model.isPhy) model.attr += STR;
    else model.attr += INT;
    if (model.isInd) model.atk += I_ATK + 115 * model.reformLV;
    else if (model.isPhy) model.atk += P_ATK + P_Growth * model.reformLV;
    else model.atk += M_ATK + M_Growth * model.reformLV;
    model.attr += 20 * model.reformLV;
}

REGIST(Gunner_28, QObject::tr("飘零之花手炮"));
