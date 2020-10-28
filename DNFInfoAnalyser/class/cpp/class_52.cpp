#include "class/h/class_52.h"

void Class_52::operator() (Character &model) { // 圣武枪魂
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 行云：冥
    int dl2 = model.passiveLVIN.at(75);
    model.minCrt += 0.5 * dl2;
    model.maxCrt += 0.5 * dl2;
    // 长枪精通
    if (model.weaponType == 30) {
        int l1 = model.passiveLVOUT.at(15) + 20;
        if (l1 > 30) l1 = 30;
        model.atk *= (1 + (2.0 * l1 - 20.0) / 100);
    }
}

REGIST(Class_52, QString::fromLocal8Bit("52"));
