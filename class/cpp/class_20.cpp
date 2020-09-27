#include "class/h/class_20.h"

void Class_20::operator() (Character &model) { // 重霄·弹药专家
    // 物理暴击/魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // G-35L感电手雷
    model.minCrt += 10;
    model.maxCrt += 10;
    // 兵器精通
    if (model.weaponType == 13 || model.weaponType == 15) {
        int l1 = model.passiveLVOUT.at(20) + 11;
        if (l1 > 20) l1 = 20;
        model.atk *= (1 + (2.0 * l1 - 10.0) / 100);
    }
}

REGIST(Class_20, QObject::tr("20"));
