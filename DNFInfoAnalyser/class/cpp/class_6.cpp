#include "class/h/class_6.h"

void Class_6::operator() (Character &model) { // 极诣·暗殿骑士
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 冥思
    model.maxCrt += 5;
    // 灵魂傀儡
    int dl2 = model.passiveLVIN.at(48);
    model.minCrt += 0.5 * dl2;
    model.maxCrt += 0.5 * dl2;
}

REGIST(Class_6, QString::fromLocal8Bit("6"));
