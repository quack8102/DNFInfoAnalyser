#include "class/h/class_2.h"

void Class_2::operator() (Character &model) { // 极诣·狂战士
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 鲜血之忆
    int l1 = model.passiveLVOUT.at(48) + model.passiveLVIN.at(48) + 20;
    if (l1 > 40) l1 = 40;
    model.minCrt += 0.6 * l1 + 2.4;
    model.maxCrt += 0.6 * l1 + 2.4;
}

REGIST(Class_2, QString::fromLocal8Bit("2"));
