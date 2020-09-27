#include "class/h/class_18.h"

void Class_18::operator() (Character &model) { // 重霄·枪炮师
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 卫星定位
    int dl2 = model.passiveLVIN.at(48);
    model.minCrt += 1.6 * dl2;
    model.maxCrt += 1.6 * dl2;
    // 重火器精通
    if (model.weaponType == 14) {
        int l1 = model.passiveLVOUT.at(15) + 11;
        if (l1 > 20) l1 = 20;
        model.atk *= (1 + l1 / 100.0);
    }
}

REGIST(Class_18, QObject::tr("18"));
