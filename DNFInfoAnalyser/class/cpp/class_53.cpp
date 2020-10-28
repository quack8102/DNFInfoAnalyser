#include "class/h/class_53.h"

void Class_53::operator() (Character &model) { // 屠戮之魂
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 光枪精通
    if (model.weaponType == 32) {
        int dl2 = model.passiveLVIN.at(15);
        model.minCrt += 0.5 * dl2;
        model.maxCrt += 0.5 * dl2;
        int l1 = model.passiveLVOUT.at(15) + 11;
        if (l1 > 20) l1 = 20;
        model.atk *= (1 + (2.0 * l1 + 5.0) / 100);
    }
}

REGIST(Class_53, QString::fromLocal8Bit("53"));
