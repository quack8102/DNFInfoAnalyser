#include "class/h/class_31.h"

void Class_31::operator() (Character &model) { // 月蚀
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 召唤兽强化
    int dl2 = model.passiveLVIN.at(15);
    model.minCrt += 0.5 * dl2;
    model.maxCrt += 0.5 * dl2;
    // 精灵召唤：融合精灵海伊伦
    int l1 = model.activeLVIN.at(60) + model.activeLVOUT.at(60) + 10;
    if (l1 > 20) l1 = 20;
    model.addAllElementIN(2 * l1 + 2);
}

REGIST(Class_31, QObject::tr("31"));
