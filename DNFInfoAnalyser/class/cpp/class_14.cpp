#include "class/h/class_14.h"

void Class_14::operator() (Character &model) { // 归元·散打
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 弱点感知
    int dl2 = model.passiveLVIN.at(30);
    model.minCrt += 1.6 * dl2;
    model.maxCrt += 1.6 * dl2;
}

REGIST(Class_14, QString::fromLocal8Bit("14"));
