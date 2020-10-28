#include "class/h/class_1.h"

void Class_1::operator() (Character &model) { // 极诣·鬼泣
    // 魔法暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 封印解除
    int dl2 = model.passiveLVIN.at(15);
    model.minCrt += 1.5 * dl2;
    model.maxCrt += 1.5 * dl2;
    // 暗月降临
    int l1 = model.passiveLVOUT.at(15) + 10;
    if (l1 > 20) l1 = 20;
    model.DARK_OUT += 5 * l1 - 20;
    // 武器精通
    if (model.weaponType == 1) { // 短剑
        QVector<int> data{0, 12, 26, 39, 51, 64, 77, 90, 103, 116, 129, 141, 154, 167, 180, 193, 206, 219, 231, 244, 257, 270, 283, 296, 309, 321, 334, 347, 360, 373, 386, 399, 411, 424, 437, 450, 463, 476, 489, 501, 514, 527, 540, 553, 566, 579, 591, 604, 617, 630, 643, 656, 669, 681, 694, 707, 720, 733, 746, 759, 771, 784, 797, 810, 823, 836, 849, 861, 874, 887, 900};
        int l2 = model.passiveLVOUT.at(15) + 31;
        if (l2 > 40) l2 = 40;
        model.atk *= (1 + data.at(l2) / 1000.0);
    } else if (model.weaponType == 2) { // 太刀
        QVector<int> data{0, 13, 28, 41, 54, 68, 82, 96, 109, 123, 137, 150, 164, 177, 191, 205, 219, 233, 245, 259, 273, 287, 301, 314, 328, 341, 355, 369, 382, 396, 410, 424, 437, 450, 464, 478, 492, 506, 520, 532, 546, 560, 574, 588, 601, 615, 628, 642, 656, 669, 683, 697, 711, 724, 737, 751, 765, 779, 793, 806, 819, 833, 847, 861, 874, 888, 902, 915, 929, 942, 956};
        int l2 = model.passiveLVOUT.at(15) + 31;
        if (l2 > 40) l2 = 40;
        model.atk *= (1 + data.at(l2) / 1000.0);
    }
}

REGIST(Class_1, QString::fromLocal8Bit("1"));
