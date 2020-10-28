#include "class/h/class_5.h"

void Class_5::operator() (Character &model) { // 极诣·驭剑士
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 冥思
    model.maxCrt += 5;
    // 人剑合一
    model.minCrt += 2 * 20;
    model.maxCrt += 2 * 20;
    // 帝皇盟约
    int l1 = model.passiveLVOUT.at(75) + 11;
    if (l1 > 40) l1 = 40;
    model.atk *= (1 + (2.0 * l1 + 28) / 100);
    // 武器精通
    if (model.weaponType == 1) { // 短剑
        int l2 = model.passiveLVOUT.at(15) + 31;
        if (l2 > 40) l2 = 40;
        model.atk *= (1 + (2.0 * l2 - 28) / 100);
    } else if (model.weaponType == 2) { // 太刀
        int l2 = model.passiveLVOUT.at(15) + 31;
        if (l2 > 40) l2 = 40;
        model.atk *= (1 + (2.0 * l2 - 29) / 100);
    } else if (model.weaponType == 3) { // 钝器
        int l2 = model.passiveLVOUT.at(15) + 31;
        if (l2 > 40) l2 = 40;
        model.atk *= (1 + (2.0 * l2 - 29) / 100);
    } else if (model.weaponType == 4) { // 巨剑
        int l2 = model.passiveLVOUT.at(15) + 31;
        if (l2 > 40) l2 = 40;
        model.atk *= (1 + (2.0 * l2 - 29) / 100);
    }
}

REGIST(Class_5, QString::fromLocal8Bit("5"));
