#include "equipment/h/title_2.h"

void Title_2::operator() (Character &model) {
        if (model.isInd) model.atk += 50;
        else model.atk += 30;
        model.attr += 55;
        model.addAllElementOUT(15);
        model.maxCrt += 5;
    }

REGIST(Title_2, QString::fromLocal8Bit("三英雄[义]"));
