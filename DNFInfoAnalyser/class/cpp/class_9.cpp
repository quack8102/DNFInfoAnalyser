#include "class/h/class_9.h"

void Class_9::operator() (Character &model) { // 归元·气功师
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 念之奥义
    int dl2 = model.passiveLVIN.at(48);
    model.minCrt += dl2;
    model.maxCrt += dl2;
    // 念气流转
    model.LIGHT_IN += 3.6 * 20 + 14;
}

REGIST(Class_9, QString::fromLocal8Bit("9"));
