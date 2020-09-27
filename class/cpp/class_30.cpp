#include "class/h/class_30.h"

void Class_30::operator() (Character &model) { // 元素圣灵
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 魔力增幅
    int dl2 = model.passiveLVIN.at(48);
    model.minCrt += 0.5 * dl2;
    model.maxCrt += 0.5 * dl2;
    int l1 = model.passiveLVOUT.at(48) + 20;
    if (l1 > 40) l1 = 40;
    model.atk *= (1 + (1.5 * l1 + 7.5) / 100);
    int l2 = l1 + model.passiveLVIN.at(48);
    if (l2 > 40) l2 = 40;
    double M_CRT = 0.5 * l2 + 7.5;
    // 圣灵符文
    int l3 = model.passiveLVIN.at(75) + model.passiveLVOUT.at(75) + 1;
    if (l3 > 40) l3 = 40;
    model.minCrt += M_CRT * (1 + (2.0 * l3 + 28.0) / 100);
    model.maxCrt += M_CRT * (1 + (2.0 * l3 + 28.0) / 100);
}

REGIST(Class_30, QObject::tr("30"));
