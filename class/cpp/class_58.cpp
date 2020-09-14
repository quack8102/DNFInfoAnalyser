#include "class/h/class_58.h"

void Class_58::operator() (Character &model) { // 未来开拓者
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 源能应用
    model.minCrt += 0.5 * 20 + 10;
    model.maxCrt += 0.5 * 20 + 10;
    // 源力剑精通
    if (model.weaponType == 37) {
        int l1 = model.passiveLVOUT.at(20) + model.passiveLVIN.at(20) + 20;
        if (l1 > 30) l1 = 30;
        model.atk *= (1 + (2.0 * l1 - 15.0) / 100);
    }
}

REGIST(Class_58, QObject::tr("58"));
