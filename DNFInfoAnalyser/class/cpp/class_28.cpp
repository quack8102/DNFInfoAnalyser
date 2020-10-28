#include "class/h/class_28.h"

void Class_28::operator() (Character &model) { // 风神
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 万象风龙阵
    model.maxCrt += 10;
    // 疾风之棍棒精通
    if (model.weaponType == 17) {
        int dl2 = model.passiveLVIN.at(15);
        model.minCrt += 0.5 * dl2;
        model.maxCrt += 0.5 * dl2;
        int l1 = model.passiveLVOUT.at(15) + 21;
        if (l1 > 30) l1 = 30;
        model.atk *= (1 + (2.0 * l1 - 20.0) / 100);
    }
}

REGIST(Class_28, QString::fromLocal8Bit("28"));
