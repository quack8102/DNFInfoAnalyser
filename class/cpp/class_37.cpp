#include "class/h/class_37.h"

void Class_37::operator() (Character &model) { // 真龙星君
    // 物理暴击/魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 巨兵精通
    int l1 = model.passiveLVOUT.at(20) + 20;
    if (l1 > 40) l1 = 40;
    model.atk *= (1 + (l1 + 10.0) / 100);
    // 式神之力
    int l2 = model.passiveLVOUT.at(75) + model.passiveLVIN.at(75) + 12;
    if (l2 > 40) l2 = 40;
    model.minCrt += 2 * l2 + 8;
    model.maxCrt += 2 * l2 + 8;
}

REGIST(Class_37, QObject::tr("37"));
