#include "class/h/class_10.h"

void Class_10::operator() (Character &model) { // 归元·散打
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 弱点感知
    int dl2 = model.passiveLVIN.at(30);
    model.minCrt += 2 * dl2;
    model.maxCrt += 2 * dl2;
    // 烈焰燃烧
    int l1 = model.passiveLVOUT.at(48) + 20;
    if (l1 > 40) l1 = 40;
    model.atk *= (1 + (l1 + 3.0) / 100);
}

REGIST(Class_10, QObject::tr("10"));
