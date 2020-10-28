#include "class/h/class_27.h"

void Class_27::operator() (Character &model) { // 血狱君主
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
}

REGIST(Class_27, QString::fromLocal8Bit("27"));
