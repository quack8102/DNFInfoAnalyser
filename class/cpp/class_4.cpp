#include "class/h/class_4.h"

void Class_4::operator() (Character &model) { // 极诣·剑影
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 幻鬼之力
    int dl2 = model.passiveLVIN.at(25);
    model.minCrt += 0.5 * dl2;
    model.maxCrt += 0.5 * dl2;
    // 鬼夜
    int dl3 = model.passiveLVIN.at(48);
    model.minCrt += 0.5 * dl3;
    model.maxCrt += 0.5 * dl3;
    // 剑影太刀精通
    if (model.weaponType == 2) {
        int l1 = model.passiveLVOUT.at(15) + model.passiveLVIN.at(15) + 11;
        if (l1 > 20) l1 = 20;
        model.atk *= (1 + 2.0 * l1 / 100);
    }
}

REGIST(Class_4, QObject::tr("4"));
