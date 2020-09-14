#include "class/h/class_0.h"

void Class_0::operator() (Character &model) { // ﻿极诣·剑魂
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 破极兵刃
    model.minCrt += 25;
    model.maxCrt += 25;
    // 流心·狂
    int l1 = model.activeLVOUT.at(30) + model.activeLVIN.at(30) + 10;
    if (l1 > 20) l1 = 20;
    model.minCrt += l1 + 4;
    model.maxCrt += l1 + 4;
    // 武器精通
    if (model.weaponType == 1) { // 短剑
        int l2 = model.passiveLVOUT.at(15) + model.passiveLVIN.at(15) + 23;
        if (l2 > 33) l2 = 33;
        model.atk *= (1 + (2.0 * l2 + 0.3) / 100);
    } else if (model.weaponType == 2) { // 太刀
        int l2 = model.passiveLVOUT.at(15) + model.passiveLVIN.at(15) + 23;
        if (l2 > 33) l2 = 33;
        model.atk *= (1 + (2.0 * l2 - 7.3) / 100);
    } else if (model.weaponType == 3) { // 钝器
        int l2 = model.passiveLVOUT.at(15) + model.passiveLVIN.at(15) + 23;
        if (l2 > 33) l2 = 33;
        model.atk *= (1 + (2.0 * l2 - 5.2) / 100);
    } else if (model.weaponType == 4) { // 巨剑
        int l2 = model.passiveLVOUT.at(15) + model.passiveLVIN.at(15) + 23;
        if (l2 > 33) l2 = 33;
        model.atk *= (1 + (2.0 * l2 - 5.6) / 100);
    } else if (model.weaponType == 5) { // 光剑
        int l2 = model.passiveLVOUT.at(15) + model.passiveLVIN.at(15) + 22;
        if (l2 > 32) l2 = 32;
        model.atk *= (1 + (2.0 * l2 - 3.0) / 100);
    }
}

REGIST(Class_0, QObject::tr("0"));
