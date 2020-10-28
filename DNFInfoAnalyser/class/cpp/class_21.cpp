#include "class/h/class_21.h"

void Class_21::operator() (Character &model) { // 绯红玫瑰
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 左轮奥义
    if (model.weaponType == 11) {
        int dl2 = model.passiveLVIN.at(15);
        model.minCrt += dl2;
        model.maxCrt += dl2;
        int l1 = model.passiveLVOUT.at(15) + 10;
        if (l1 > 20) l1 = 20;
        model.atk *= (1 + (2.0 * l1) / 100);
    }
}

REGIST(Class_21, QString::fromLocal8Bit("21"));
