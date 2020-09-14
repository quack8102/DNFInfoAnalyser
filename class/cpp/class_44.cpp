#include "class/h/class_44.h"

void Class_44::operator() (Character &model) { // 亡魂主宰
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 屠戮之惧
    int dl2 = model.passiveLVIN.at(48);
    model.minCrt += 0.5 * dl2;
    model.maxCrt += 0.5 * dl2;
    // 黑暗之环
    int l1 = model.passiveLVIN.at(20) + model.passiveLVOUT.at(20) + 10;
    if (l1 > 20) l1 = 20;
    model.DARK_OUT += 3 * l1 + 48;
}

REGIST(Class_44, QObject::tr("44"));
