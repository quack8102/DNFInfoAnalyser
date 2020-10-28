#include "class/h/class_26.h"

void Class_26::operator() (Character &model) { // 刹那永恒
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 冰霜之径
    int l1 = model.activeLVOUT.at(25) + 10;
    if (l1 > 20) l1 = 20;
    model.ICE_OUT += 4 * l1 + 30;
    // 冰之领悟
    int dl2 = model.passiveLVIN.at(25);
    model.minCrt += dl2;
    model.maxCrt += dl2;
    int l2 = model.passiveLVOUT.at(25) + 10;
    if (l2 > 20) l2 = 20;
    model.atk *= (1 + (2.0 * l2 - 8.0) / 100);
}

REGIST(Class_26, QString::fromLocal8Bit("26"));
