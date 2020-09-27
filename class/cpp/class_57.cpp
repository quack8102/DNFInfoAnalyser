#include "class/h/class_57.h"

void Class_57::operator() (Character &model) { // 巅峰狂徒
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 终极火力
    int dl2 = model.passiveLVIN.at(48);
    model.minCrt += 0.5 * dl2;
    model.maxCrt += 0.5 * dl2;
    // 重剑精通
    if (model.weaponType == 36) {
        int l1 = model.passiveLVOUT.at(20) + 21;
        if (l1 > 30) l1 = 30;
        model.atk *= (1 + (2.5 * l1 - 25.0) / 100);
    }
}

REGIST(Class_57, QObject::tr("57"));
