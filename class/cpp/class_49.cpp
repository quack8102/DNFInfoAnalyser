#include "class/h/class_49.h"

void Class_49::operator() (Character &model) { // 破晓女神
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 天使光翼
    int l1 = model.passiveLVIN.at(15) + model.passiveLVOUT.at(15) + 11;
    if (l1 > 20) l1 = 20;
    model.minCrt += 0.5 * l1 + 25;
    model.maxCrt += 0.5 * l1 + 25;
    if (model.weaponType == 3) {
        model.atk *= (1 + (2.0 * l1 - 10.0) / 100);
    }
    // 天使降临
    int l2 = model.passiveLVIN.at(15) + model.passiveLVOUT.at(15) + 10;
    if (l2 > 20) l2 = 20;
    model.atk *= (1 + (2.0 * l2 - 2.0) / 100);
    // 荣耀之光
    int l3 = model.passiveLVIN.at(48) + model.passiveLVOUT.at(48) + 20;
    if (l3 > 40) l3 = 40;
    model.atk *= (1 + (1.5 * l3 + 10.5) / 100);
}

REGIST(Class_49, QObject::tr("49"));
