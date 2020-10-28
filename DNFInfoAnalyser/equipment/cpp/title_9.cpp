#include "equipment/h/title_9.h"

void Title_9::operator() (Character &model) {
        if (model.isInd) model.atk += 55;
        else model.atk += 35;
        model.attr += 65;
        model.addAllElementOUT(15);
        model.maxCrt += 5;
    }

REGIST(Title_9, QString::fromLocal8Bit("龙之威仪"));
