#include "class/h/class_38.h"

void Class_38::operator() (Character &model) { // 永生者
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 镰刀精通
    if (model.weaponType == 24) {
        model.minCrt += int(0.5 * dl1);
        model.maxCrt += int(0.5 * dl1);
        int l1 = model.passiveLVOUT.at(20) + model.passiveLVIN.at(20) + 10;
        if (l1 > 20) l1 = 20;
        model.atk *= (1 + (2.0 * l1) / 100);
    }
}

REGIST(Class_38, QObject::tr("38"));
