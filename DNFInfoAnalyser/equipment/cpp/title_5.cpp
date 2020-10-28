#include "equipment/h/title_5.h"

void Title_5::operator() (Character &model) {
        model.attr += 55;
        model.addAllElementOUT(15);
        model.addAllElementIN(10);
    }

REGIST(Title_5, QString::fromLocal8Bit("最强战王"));
