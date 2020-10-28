#include "class/h/class_34.h"

void Class_34::operator() (Character &model) { // 冥月女神
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
}

REGIST(Class_34, QString::fromLocal8Bit("34"));
