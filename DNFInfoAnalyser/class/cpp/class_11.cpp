#include "class/h/class_11.h"

void Class_11::operator() (Character &model) { // 归元·街霸
    // 物理暴击/魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 千手奥义
    int dl2 = model.passiveLVIN.at(48);
    model.minCrt += 0.5 * dl2;
    model.maxCrt += 0.5 * dl2;
    // 爪精通
    if (model.weaponType == 8) {
        int l1 = model.passiveLVOUT.at(25) + 20;
        if (l1 > 30) l1 = 30;
        model.atk *= (1 + (2.0 * l1 - 9.0) / 100);
    }
}

REGIST(Class_11, QString::fromLocal8Bit("11"));
