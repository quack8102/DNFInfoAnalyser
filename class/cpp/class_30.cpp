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
    int l1 = model.passiveLVIN.at(48) + model.passiveLVOUT.at(48) + 20;
    if (l1 > 40) l1 = 40;
    double M_CRT = 0.5 * l1 + 7.5;
    model.atk *= (1 + (1.5 * l1 + 7.5) / 100);
    // 圣灵符文 数据可能有误
    model.minCrt += 0.3 * M_CRT;
    model.maxCrt += 0.3 * M_CRT;
}

REGIST(Class_30, QObject::tr("30"));
