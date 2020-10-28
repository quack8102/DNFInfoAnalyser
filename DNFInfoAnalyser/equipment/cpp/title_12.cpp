#include "equipment/h/title_12.h"

void Title_12::operator() (Character &model) {
        if (model.isInd) model.atk += 55;
        else model.atk += 35;
        model.attr += 75;
        model.addAllElementOUT(20);
        model.maxCrt += 5;
    }

REGIST(Title_12, QString::fromLocal8Bit("天选之人"));
