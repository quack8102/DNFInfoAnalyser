#include "class/h/class_48.h"

void Class_48::operator() (Character &model) { // 黑曜神
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 盾牌
    model.atk += 10;
}

REGIST(Class_48, QObject::tr("48"));