#include "class/h/class_13.h"

void Class_13::operator() (Character &model) { // 归元·气功师
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 乱舞·千叶花
    int dl2 = model.passiveLVIN.at(48);
    model.minCrt += 0.5 * dl2;
    model.maxCrt += 0.5 * dl2;
    // 光之兵刃
    model.LIGHT_IN += 3.6 * 20 + 14;
}

REGIST(Class_13, QString::fromLocal8Bit("13"));
