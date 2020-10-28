#include "class/h/class_51.h"

void Class_51::operator() (Character &model) { // 不灭战神
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 不灭战戟
    model.minCrt += 20 + 10;
    model.maxCrt += 20 + 10;
    // 战戟精通
    if (model.weaponType == 31) {
        int l1 = model.passiveLVOUT.at(15) + 10;
        if (l1 > 20) l1 = 20;
        model.atk *= (1 + (2.0 * l1 + 10.0) / 100);
    }
}

REGIST(Class_51, QString::fromLocal8Bit("51"));
