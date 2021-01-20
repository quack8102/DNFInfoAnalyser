#include "equipment/h/title_36.h"

void Title_36::operator() (Character &model) { // 永恒战吼
    model.attr += 80;
    model.atk += 60;
    model.addAllElementOUT(15);
    model.maxCrt += 5;
}

REGIST(Title_36, QString::fromLocal8Bit("永恒战吼"));