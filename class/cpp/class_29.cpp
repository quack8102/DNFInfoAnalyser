#include "class/h/class_29.h"

void Class_29::operator() (Character &model) { // 混沌行者
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 次元扭曲装置
    model.minCrt += 0.5 * dl1;
    model.maxCrt += 0.5 * dl1;
    // 虚空之力
    int l1 = model.passiveLVOUT.at(48) + model.passiveLVIN.at(48) + 20;
    if (l1 > 40) l1 = 40;
    model.minCrt += 0.5 * l1 + 5.5;
    model.maxCrt += 0.5 * l1 + 5.5;
}

REGIST(Class_29, QObject::tr("29"));
