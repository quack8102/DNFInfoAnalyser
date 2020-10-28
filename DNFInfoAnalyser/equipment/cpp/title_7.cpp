#include "equipment/h/title_7.h"

void Title_7::operator() (Character &model) {
        model.attr += 55;
        model.addAllElementOUT(15);
        model.addAllElementIN(10);
    }

REGIST(Title_7, QString::fromLocal8Bit("最强战神"));
