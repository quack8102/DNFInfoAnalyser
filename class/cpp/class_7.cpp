#include "class/h/class_7.h"

void Class_7::operator() (Character &model) { // 极诣·契魔者
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 冥思
    model.maxCrt += 5;
    // 魔剑控制
    int dl2 = model.passiveLVIN.at(30);
    model.minCrt += 0.5 * dl2;
    model.maxCrt += 0.5 * dl2;
    int l1 = model.passiveLVOUT.at(30) + model.passiveLVIN.at(30) + 21;
    if (l1 > 30) l1 = 30;
    model.atk *= (1 + (2.5 * l1 - 20.0) / 100);
}

REGIST(Class_7, QObject::tr("7"));
