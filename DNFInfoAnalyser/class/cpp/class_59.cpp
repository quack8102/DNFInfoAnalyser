#include "class/h/class_59.h"

void Class_59::operator() (Character &model) { // 缔造者
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 时空增幅
    model.minCrt += 20;
    model.maxCrt += 20;
    // 自我觉醒
    model.atk *= 1.11;
    // 幻想之境
    int l1 = model.passiveLVOUT.at(20) + 10;
    if (l1 > 20) l1 = 20;
    model.atk *= (1 + (1.5 * l1 - 5.0) / 100);
}

REGIST(Class_59, QString::fromLocal8Bit("59"));
