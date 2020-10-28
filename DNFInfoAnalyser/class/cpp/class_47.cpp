#include "class/h/class_47.h"

void Class_47::operator() (Character &model) { // 大地女神
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 盾牌
    if (model.mode) model.atk += 7;
    // 骑士信念
    int dl2 = model.passiveLVIN.at(15);
    model.minCrt += dl2;
    model.maxCrt += dl2;
    int l1 = model.passiveLVOUT.at(15) + 10;
    if (l1 > 20) l1 = 20;
    model.atk *= (1 + (2.0 * l1 + 10.0) / 100);
}

REGIST(Class_47, QString::fromLocal8Bit("47"));
