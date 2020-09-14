#include "class/h/class_23.h"

void Class_23::operator() (Character &model) { // 机械之灵
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
}

REGIST(Class_23, QObject::tr("23"));
