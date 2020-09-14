#include "class/h/class_16.h"

void Class_16::operator() (Character &model) { // 归元·柔道家
    // 物理暴击
    int dl1 = model.passiveLVIN.at(20);
    model.minCrt += dl1;
    model.maxCrt += dl1;
    // 强力抱摔
    model.minCrt += 0.5 * dl1;
    model.maxCrt += 0.5 * dl1;
    // 抓取奥义
    int dl2 = model.passiveLVIN.at(48);
    model.minCrt += 0.5 * dl2;
    model.maxCrt += 0.5 * dl2;
}

REGIST(Class_16, QObject::tr("16"));
