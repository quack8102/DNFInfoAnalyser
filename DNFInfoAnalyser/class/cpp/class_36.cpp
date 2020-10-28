#include "class/h/class_36.h"

void Class_36::operator() (Character &model) { // 正义仲裁者
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 意念驱动
    int l1 = model.activeLVIN.at(15) + model.activeLVOUT.at(15) + 10;
    if (l1 > 20) l1 = 20;
    model.minCrt += 1.5 * l1;
    model.maxCrt += 1.5 * l1;
}

REGIST(Class_36, QString::fromLocal8Bit("36"));
