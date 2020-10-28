#include "equipment/h/title_28.h"

void Title_28::operator() (Character &model) { // 伊希斯的天空
    model.attr += 60;
    model.addAllElementOUT(15);
    model.addAllElementIN(10);
}

REGIST(Title_28, QString::fromLocal8Bit("伊希斯的天空"));
