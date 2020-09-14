#include "class/h/class_12.h"

void Class_12::operator() (Character &model) { // 归元·柔道家
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 傲天之怒
    int dl2 = model.passiveLVIN.at(75);
    model.minCrt += 2 * dl2;
    model.maxCrt += 2 * dl2;
}

REGIST(Class_12, QObject::tr("12"));
