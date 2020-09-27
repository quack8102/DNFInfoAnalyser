#include "class/h/class_42.h"

void Class_42::operator() (Character &model) { // 救世主
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 镰刀精通
    if (model.weaponType == 24) {
        int l1 = model.passiveLVOUT.at(20) + 20;
        if (l1 > 30) l1 = 30;
        model.atk *= (1 + (2.0 * l1 - 15.0) / 100);
    }
    // 罪业宣告
    int l2 = model.passiveLVOUT.at(48) + model.passiveLVIN.at(48) + 20;
    if (l2 > 40) l2 = 40;
    model.minCrt += 0.5 * l2 + 13;
    model.maxCrt += 0.5 * l2 + 13;
}

REGIST(Class_42, QObject::tr("42"));
