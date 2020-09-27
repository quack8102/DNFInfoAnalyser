#include "class/h/class_22.h"

void Class_22::operator() (Character &model) { // 风暴骑兵
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 重火器精通
    if (model.weaponType == 14) {
        int l1 = model.passiveLVOUT.at(15) + 11;
        if (l1 > 20) l1 = 20;
        model.atk *= (1 + l1 / 100.0);
    }
    // APG-63
    int dl2 = model.passiveLVIN.at(25);
    model.minCrt += dl2;
    model.maxCrt += dl2;
    int l2 = model.passiveLVOUT.at(25) + 10;
    if (l2 > 20) l2 = 20;
    model.atk *= (1 + (l2 + 14.0) / 100);
}

REGIST(Class_22, QObject::tr("22"));
