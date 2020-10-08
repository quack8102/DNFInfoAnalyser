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
    QVector<int> data{0, 12, 22, 31, 41, 51, 61, 70, 80, 90, 100, 109, 119, 129, 139, 148, 158, 168, 178, 187, 197, 207, 217, 226, 236, 246, 256, 265, 275, 285, 294, 304, 314, 324, 333, 343, 353, 363, 372, 382, 392, 402, 411, 421, 431, 441, 450, 460, 470, 480, 489, 499, 509, 518, 528, 538, 548, 557, 567, 577, 587, 596, 606, 616, 626, 635, 645, 655, 665, 674, 684};
    int l1 = model.passiveLVIN.at(15) + model.passiveLVOUT.at(15) + 46;
    if (l1 > 60) l1 = 60;
    model.minCrt += data.at(l1) / 10.0;
    model.maxCrt += data.at(l1) / 10.0;
    // 武器精通
    if (model.weaponType == 16) { // 矛
        model.minCrt += 0.6 * dl1;
        model.maxCrt += 0.6 * dl1;
        int l2 = model.passiveLVOUT.at(20) + 20;
        if (l2 > 30) l2 = 30;
        model.atk *= (1 + (2.0 * l2 - 20.0) / 100);
    } else if (model.weaponType == 17) { // 棍棒 数据可能有误
        model.minCrt += 0.6 * dl1;
        model.maxCrt += 0.6 * dl1;
        int l2 = model.passiveLVOUT.at(20) + 20;
        if (l2 > 30) l2 = 30;
        model.atk *= (1 + (2.0 * l2 - 20.0) / 100);
    }
}

REGIST(Class_32, QObject::tr("32"));
