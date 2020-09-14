#include "class/h/class_17.h"

void Class_17::operator() (Character &model) { // 重霄·漫游枪手
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 死亡印记 数据可能有误
    QVector<double> data{0, 1.6, 2.6, 3.8, 4.9, 6.1, 7.2, 8.3, 9.4, 10.6, 11.7, 12.7, 13.9, 15, 16.2, 17.3, 18.4, 19.5, 20.7, 21.8, 22.8, 24, 25.1, 26.3, 27.4, 28.5, 29.6, 30.8, 31.9, 32.9, 34.1, 35.2, 36.4, 37.5, 38.6, 39.7, 40.9, 42, 43, 44.2, 45.3};
    int l1 = model.passiveLVOUT.at(48) + model.passiveLVIN.at(48) + 20;
    if (l1 > 40) l1 = 40;
    model.minCrt += data.at(l1);
    model.maxCrt += data.at(l1);
    // 左轮奥义
    if (model.weaponType == 11) {
        int dl2 = model.passiveLVIN.at(15);
        model.minCrt += dl2;
        model.maxCrt += dl2;
        int l2 = model.passiveLVOUT.at(15) + model.passiveLVIN.at(15) + 10;
        if (l2 > 20) l2 = 20;
        model.atk *= (1 + (2.0 * l2) / 100);
    }
}

REGIST(Class_17, QObject::tr("17"));
