#include "equipment/h/fighter_28.h"

void Fighter_28::operator() (Character &model) { // 飘零之花拳套
    int P_ATK = 1190, M_ATK = 1067, I_ATK = 711;
    int P_Growth = 187, M_Growth = 186;
    int STR = 81, INT = 0;
    if (model.isPhy) model.attr += STR;
    else model.attr += INT;
    if (model.isInd) model.atk += I_ATK + 115 * model.reformLV;
    else if (model.isPhy) model.atk += P_ATK + P_Growth * model.reformLV;
    else model.atk += M_ATK + M_Growth * model.reformLV;
    model.attr += 20 * model.reformLV;
}

REGIST(Fighter_28, QObject::tr("飘零之花拳套"));
