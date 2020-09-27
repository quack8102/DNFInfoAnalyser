#include "class/h/class_40.h"

void Class_40::operator() (Character &model) { // 炎狱裁决者
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 狂热信仰
    model.minCrt += 20;
    model.maxCrt += 20;
    // 战斧精通
    if (model.weaponType == 25) {
        int l1 = model.passiveLVOUT.at(20) + 11;
        if (l1 > 20) l1 = 20;
        model.atk *= (1 + (2.0 * l1 - 5.0) / 100);
    }
}

REGIST(Class_40, QObject::tr("40"));
