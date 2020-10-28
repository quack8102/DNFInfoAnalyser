#include "class/h/class_3.h"

void Class_3::operator() (Character &model) { // 极诣·阿修罗
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 杀意波动
    model.minCrt += 20;
    model.maxCrt += 20;
    // 封印解除
    int dl2 = model.passiveLVIN.at(15);
    model.minCrt += 1.5 * dl2;
    model.maxCrt += 1.5 * dl2;
}

REGIST(Class_3, QString::fromLocal8Bit("3"));
