#include "equipment/h/gunner_25.h"

void Gunner_25::operator() (Character &model) { // 飘零之花左轮枪
    int P_ATK = 1137, M_ATK = 942, I_ATK = 711;
    int P_Growth = 185, M_Growth = 183;
    int STR = 81, INT = 0;
    if (model.isPhy) model.attr += STR;
    else model.attr += INT;
    if (model.isInd) model.atk += I_ATK + 115 * model.reformLV;
    else if (model.isPhy) model.atk += P_ATK + P_Growth * model.reformLV;
    else model.atk += M_ATK + M_Growth * model.reformLV;
    model.attr += 20 * model.reformLV;
}

REGIST(Gunner_25, QObject::tr("飘零之花左轮枪"));
