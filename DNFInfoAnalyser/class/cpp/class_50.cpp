#include "class/h/class_50.h"

void Class_50::operator() (Character &model) { // 龙神
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 龙人太刀精通
    if (model.weaponType == 2) {
        int dl2 = model.passiveLVIN.at(25);
        model.minCrt += dl2;
        model.maxCrt += dl2;
    }
    // 龙神血脉
    int dl3 = model.passiveLVIN.at(75);
    model.minCrt += 0.5 * dl3;
    model.maxCrt += 0.5 * dl3;
}

REGIST(Class_50, QString::fromLocal8Bit("50"));
