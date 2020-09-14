#include "class/h/class_35.h"

void Class_35::operator() (Character &model) { // 神思者
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 圣灵之槌
    model.minCrt += 0.5 * 30;
    model.maxCrt += 0.5 * 30;
}

REGIST(Class_35, QObject::tr("35"));
