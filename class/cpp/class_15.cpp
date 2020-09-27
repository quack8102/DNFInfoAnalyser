#include "class/h/class_15.h"

void Class_15::operator() (Character &model) { // 归元·街霸
    // 物理暴击/魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 猛毒之伤
    int l1 = model.passiveLVOUT.at(75) + model.passiveLVIN.at(75) + 11;
    if (l1 > 40) l1 = 40;
    model.minCrt += 2 * l1 + 8;
    model.maxCrt += 2 * l1 + 8;
    // 爪精通
    if (model.weaponType == 8) {
        int l2 = model.passiveLVOUT.at(25) + 20;
        if (l2 > 30) l2 = 30;
        model.atk *= (1 + (l2 + 21.0) / 100);
    }
}

REGIST(Class_15, QObject::tr("15"));
