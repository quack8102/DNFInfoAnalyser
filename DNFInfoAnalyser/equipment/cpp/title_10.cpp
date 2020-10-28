#include "equipment/h/title_10.h"

void Title_10::operator() (Character &model) {
        model.attr += 55;
        model.addAllElementOUT(15);
        model.addAllElementIN(10);
    }

REGIST(Title_10, QString::fromLocal8Bit("海洋霸主"));
