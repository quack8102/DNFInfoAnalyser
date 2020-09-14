#include "class/h/class_46.h"

void Class_46::operator() (Character &model) { // 幽冥
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 暗杀信条
    model.minCrt += 1.1 * 20 + 8.9;
    model.maxCrt += 1.1 * 20 + 8.9;
    // 暗杀之心
    int l1 = model.passiveLVOUT.at(48) + model.passiveLVIN.at(48) + 20;
    if (l1 > 40) l1 = 40;
    model.minCrt += l1;
    model.maxCrt += l1;
    // 暗杀之匕首精通
    if (model.weaponType == 26) {
        int l2 = model.passiveLVOUT.at(20) + model.passiveLVIN.at(20) + 20;
        if (l2 > 30) l2 = 30;
        model.atk *= (1 + (2.5 * l2 - 20.0) / 100);
    }
}

REGIST(Class_46, QObject::tr("46"));
