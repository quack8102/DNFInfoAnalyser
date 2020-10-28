#include "class/h/class_54.h"

void Class_54::operator() (Character &model) { // 幽影夜神
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 暗矛精通
    if (model.weaponType == 33) {
        int l1 = model.passiveLVOUT.at(20) + 21;
        if (l1 > 30) l1 = 30;
        model.atk *= (1 + (2.0 * l1 - 20.0) / 100);
    }
    // 黑暗化身
    model.minCrt += 20;
    model.maxCrt += 20;
    // 暗蚀
    int l2 = model.passiveLVOUT.at(15) + 10;
    if (l2 > 20) l2 = 20;
    model.DARK_OUT += 4 * l2 + 30;
}

REGIST(Class_54, QString::fromLocal8Bit("54"));
