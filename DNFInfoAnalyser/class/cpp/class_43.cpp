#include "class/h/class_43.h"

void Class_43::operator() (Character &model) { // 月影星劫
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 月弧
    int l1 = model.passiveLVOUT.at(48) + model.passiveLVIN.at(48) + 20;
    if (l1 > 40) l1 = 40;
    model.minCrt += 2 * l1 + 2;
    model.maxCrt += 2 * l1 + 2;
    // 武器精通
    if (model.weaponType == 26 || model.weaponType == 27) { // 双剑 匕首
        int l2 = model.passiveLVOUT.at(20) + 21;
        if (l2 > 30) l2 = 30;
        model.atk *= (1 + (2.8 * l2 - 20.1) / 100);
    }
}

REGIST(Class_43, QString::fromLocal8Bit("43"));
