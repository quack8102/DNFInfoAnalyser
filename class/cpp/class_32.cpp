#include "class/h/class_32.h"

void Class_32::operator() (Character &model) { // 伊斯塔战灵
    // 物理暴击/魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 尼巫的战术
    int dl2 = model.passiveLVIN.at(15);
    model.minCrt += 0.5 * dl2;
    model.maxCrt += 0.5 * dl2;
    // 炫纹
    int l1 = model.passiveLVIN.at(15) + model.passiveLVOUT.at(15) + 46;
    if (l1 > 60) l1 = 60;
    model.minCrt += l1 + 0.2 - 0.1 * int((l1 + 1) / 4);
    model.maxCrt += l1 + 0.2 - 0.1 * int((l1 + 1) / 4);
    // 武器精通
    if (model.weaponType == 16) { // 矛
        model.minCrt += 0.6 * dl1;
        model.maxCrt += 0.6 * dl1;
        int l2 = model.passiveLVOUT.at(20) + model.passiveLVIN.at(20) + 20;
        if (l2 > 30) l2 = 30;
        model.atk *= (1 + (2.0 * l2 - 20.0) / 100);
    } else if (model.weaponType == 17) { // 棍棒 数据可能有误
        model.minCrt += 0.6 * dl1;
        model.maxCrt += 0.6 * dl1;
        int l2 = model.passiveLVOUT.at(20) + model.passiveLVIN.at(20) + 20;
        if (l2 > 30) l2 = 30;
        model.atk *= (1 + (2.0 * l2 - 20.0) / 100);
    }
}

REGIST(Class_32, QObject::tr("32"));
