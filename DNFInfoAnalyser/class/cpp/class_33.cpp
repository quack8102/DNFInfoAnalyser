#include "class/h/class_33.h"

void Class_33::operator() (Character &model) { // 古灵精怪
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 成功预感
    int dl2 = model.passiveLVIN.at(48);
    model.minCrt += 0.7 * dl2;
    model.maxCrt += 0.7 * dl2;
}

REGIST(Class_33, QString::fromLocal8Bit("33"));
