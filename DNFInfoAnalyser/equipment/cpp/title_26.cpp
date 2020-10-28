#include "equipment/h/title_26.h"

void title_26::operator() (Character &model) { // 卢克的创造
    model.attr += 60;
    model.addAllElementOUT(15);
    model.addAllElementIN(10);
}

REGIST(title_26, QString::fromLocal8Bit("卢克的创造"));
