#include "class/h/class_25.h"

void Class_25::operator() (Character &model) { // 湮灭之瞳
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 元素爆发
    int dl2 = model.passiveLVIN.at(48);
    model.minCrt += 0.5 * dl2;
    model.maxCrt += 0.5 * dl2;
    // 元素融合
    int l1 = model.passiveLVIN.at(15) + model.passiveLVOUT.at(15) + 1;
    if (l1 > 11) l1 = 11;
    model.addAllElementIN(3 * l1 + 37);
    // 元素环绕
    int l2 = model.activeLVIN.at(25) + model.activeLVOUT.at(25) + 10;
    if (l2 > 20) l2 = 20;
    model.addAllElementIN(3 * l2 + 6);
}

REGIST(Class_25, QObject::tr("25"));
