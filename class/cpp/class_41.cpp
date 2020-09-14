#include "class/h/class_41.h"

void Class_41::operator() (Character &model) { // 神龙天女
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 神术强化
    int dl2 = model.passiveLVIN.at(30);
    model.minCrt += 1.5 * dl2;
    model.maxCrt += 1.5 * dl2;
}

REGIST(Class_41, QObject::tr("41"));
