#include "equipment/h/title_34.h"

void Title_34::operator() (Character &model) { // 永恒追猎
    model.attr += 80;
    model.atk += 60;
    model.addAllElementOUT(15);
    model.maxCrt += 5;
}

REGIST(Title_34, QString::fromLocal8Bit("永恒追猎"));