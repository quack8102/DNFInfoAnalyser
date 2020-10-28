#include "class/h/class_19.h"

void Class_19::operator() (Character &model) { // 重霄·机械师
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 方舟反应堆
    int dl2 = model.passiveLVIN.at(25);
    model.minCrt += 0.5 * dl2;
    model.maxCrt += 0.5 * dl2;
}

REGIST(Class_19, QString::fromLocal8Bit("19"));
