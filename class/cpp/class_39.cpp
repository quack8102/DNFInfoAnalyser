#include "class/h/class_39.h"

void Class_39::operator() (Character &model) { // 炽天使
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
}

REGIST(Class_39, QObject::tr("39"));
