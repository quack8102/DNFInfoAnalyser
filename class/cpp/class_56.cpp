#include "class/h/class_56.h"

void Class_56::operator() (Character &model) { // 弑心镇魂者
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 特工秘技
    int dl2 = model.passiveLVIN.at(15);
    model.minCrt += dl2;
    model.maxCrt += dl2;
    // 冷酷杀意
    int dl3 = model.passiveLVIN.at(75);
    model.minCrt += dl3;
    model.maxCrt += dl3;
    // 小太刀精通
    if (model.weaponType == 35) {
        int l1 = model.passiveLVOUT.at(20) + model.passiveLVIN.at(20) + 11;
        if (l1 > 20) l1 = 20;
        model.atk *= (1 + (2.0 * l1 - 5.0) / 100);
    }
}

REGIST(Class_56, QObject::tr("56"));
