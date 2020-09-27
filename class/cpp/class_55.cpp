#include "class/h/class_55.h"

void Class_55::operator() (Character &model) { // 铁血统帅
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 长刀精通
    if (model.weaponType == 34) {
        int l1 = model.passiveLVOUT.at(15) + 11;
        if (l1 > 20) l1 = 20;
        model.atk *= (1 + (2.0 * l1 + 5.0) / 100);
    }
    // 电光飞掠
    model.maxCrt += 10;
    // 暗刃战略
    int dl2 = model.passiveLVIN.at(25);
    model.minCrt += dl2;
    model.maxCrt += dl2;
}

REGIST(Class_55, QObject::tr("55"));
