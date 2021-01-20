#include "equipment/h/title_35.h"

void Title_35::operator() (Character &model) { // 永恒判罪
    model.attr += 80;
    model.atk += 60;
    model.addAllElementOUT(15);
    model.maxCrt += 5;
}

REGIST(Title_35, QString::fromLocal8Bit("永恒判罪"));