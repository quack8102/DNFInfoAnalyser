#include "equipment/h/demoniclancer_22.h"

void Demoniclancer_22::operator() (Character &model) { // 飘零之花光枪
    int P_ATK = 1067, M_ATK = 1313, I_ATK = 711;
    int P_Growth = 186, M_Growth = 189;
    int STR = 81, INT = 81;
    if (model.isPhy) model.attr += STR;
    else model.attr += INT;
    if (model.isInd) model.atk += I_ATK + 115 * model.reformLV;
    else if (model.isPhy) model.atk += P_ATK + P_Growth * model.reformLV;
    else model.atk += M_ATK + M_Growth * model.reformLV;
    model.attr += 20 * model.reformLV;
}

REGIST(Demoniclancer_22, QString::fromLocal8Bit("飘零之花光枪"));
