#include "class/h/class_17.h"

void Class_17::operator() (Character &model) { // 重霄·漫游枪手
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 死亡印记
    QVector<int> data{0, 16, 26, 38, 49, 61, 72, 83, 94, 106, 117, 127, 139, 150, 162, 173, 184, 195, 207, 218, 228, 240, 251, 263, 274, 285, 296, 308, 319, 330, 341, 352, 364, 375, 386, 397, 409, 420, 431, 442, 453};
    int l1 = model.passiveLVOUT.at(48) + model.passiveLVIN.at(48) + 20;
    if (l1 > 40) l1 = 40;
    model.minCrt += data.at(l1) / 10.0;
    model.maxCrt += data.at(l1) / 10.0;
    // 左轮奥义
    if (model.weaponType == 11) {
        int dl2 = model.passiveLVIN.at(15);
        model.minCrt += dl2;
        model.maxCrt += dl2;
        int l2 = model.passiveLVOUT.at(15) + 10;
        if (l2 > 20) l2 = 20;
        model.atk *= (1 + (2.0 * l2) / 100);
    }
}

REGIST(Class_17, QString::fromLocal8Bit("17"));
