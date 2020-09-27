#include "class/h/class_8.h"

void Class_8::operator() (Character &model) { // 极诣·流浪武士
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 冥思
    model.maxCrt += 5;
    // 花开寒影
    model.maxCrt += 15;
    // 副武器可装备
    if (model.mode) {
        model.attr += int(0.1 * 81);
        model.atk += int(0.1 * (1143 + 828));
    }
}

REGIST(Class_8, QObject::tr("8"));
