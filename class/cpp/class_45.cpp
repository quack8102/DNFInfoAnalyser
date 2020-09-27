#include "class/h/class_45.h"

void Class_45::operator() (Character &model) { // 不知火
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 苦无精通
    if (model.weaponType == 29) {
        int l1 = model.passiveLVOUT.at(25) + 10;
        if (l1 > 20) l1 = 20;
        model.atk *= (1 + (l1 + 23.0) / 100);
    }
    // 毕方之印
    int dl2 = model.passiveLVIN.at(48);
    model.minCrt += 0.5 * dl2;
    model.maxCrt += 0.5 * dl2;
    int l2 = model.passiveLVOUT.at(48) + 20;
    if (l2 > 40) l2 = 40;
    model.FIRE_OUT += 2 * l2 + 30;
}

REGIST(Class_45, QObject::tr("45"));
