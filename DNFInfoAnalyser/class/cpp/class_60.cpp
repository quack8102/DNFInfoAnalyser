#include "class/h/class_60.h"

void Class_60::operator() (Character &model) { // 黑暗武士
    // 物理暴击/魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 次元融合
    int dl2 = model.passiveLVIN.at(75);
    model.minCrt += 0.5 * dl2;
    model.maxCrt += 0.5 * dl2;
    int l1 = model.passiveLVOUT.at(75) + 12;
    if (l1 > 40) l1 = 40;
    model.attr *= (1 + (2.0 * l1) / 100);
    // 自我觉醒
    model.atk *= 1.11;
    // 武器精通
    if (model.weaponType == 1) { // 短剑
        QVector<int> data{0, 12, 26, 39, 51, 64, 77, 90, 103, 116, 129, 141, 154, 167, 180, 193, 206, 219, 231, 244, 257, 270, 283, 296, 309, 321, 334, 347, 360, 373, 386, 399, 411, 424, 437, 450, 463, 476, 489, 501, 514, 527, 540, 553, 566, 579, 591, 604, 617, 630, 643, 656, 669, 681, 694, 707, 720, 733, 746, 759, 771, 784, 797, 810, 823, 836, 849, 861, 874, 887, 900};
        int l2 = model.passiveLVOUT.at(15) + 30;
        if (l2 > 40) l2 = 40;
        if (model.isPhy) model.atk *= (1 + (1.5 * l2) / 100);
        else model.atk *= (1 + data.at(l2) / 1000.0);
    } else if (model.weaponType == 2) { // 太刀
        int l2 = model.passiveLVOUT.at(15) + 30;
        if (l2 > 40) l2 = 40;
        if (model.isPhy) model.atk *= (1 + (1.3 * l2) / 100);
        else model.atk *= (1 + (1.2 * l2) / 100);
    } else if (model.weaponType == 3) { // 钝器
        int l2 = model.passiveLVOUT.at(15) + 30;
        if (l2 > 40) l2 = 40;
        model.atk *= (1 + (1.2 * l2) / 100);
    } else if (model.weaponType == 4) { // 巨剑
        int l2 = model.passiveLVOUT.at(15) + 30;
        if (l2 > 40) l2 = 40;
        model.atk *= (1 + (1.2 * l2) / 100);
    } else if (model.weaponType == 5) { // 光剑
        QVector<int> data{0, 26, 40, 53, 66, 79, 92, 106, 119, 132, 145, 158, 172, 185, 198, 211, 224, 238, 251, 264, 277, 290, 304, 317, 330, 343, 356, 370, 383, 396, 409, 422, 436, 449, 462, 475, 488, 502, 515, 528, 541, 554, 568, 581, 594, 607, 620, 634, 647, 660, 660};
        int l2 = model.passiveLVOUT.at(15) + 30;
        if (l2 > 40) l2 = 40;
        model.atk *= (1 + data.at(l2) / 1000.0);
    }
}

REGIST(Class_60, QString::fromLocal8Bit("60"));
