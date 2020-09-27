#include "equipment/h/gunner_26.h"

void Gunner_26::operator() (Character &model) { // 飘零之花自动手枪
    int P_ATK = 768, M_ATK = 1173, I_ATK = 711;
    int P_Growth = 181, M_Growth = 186;
    int STR = 0, INT = 81;
    if (model.isPhy) model.attr += STR;
    else model.attr += INT;
    if (model.isInd) model.atk += I_ATK + 115 * model.reformLV;
    else if (model.isPhy) model.atk += P_ATK + P_Growth * model.reformLV;
    else model.atk += M_ATK + M_Growth * model.reformLV;
    model.attr += 20 * model.reformLV;
}

REGIST(Gunner_26, QObject::tr("飘零之花自动手枪"));
