#include "equipment/h/title_15.h"

void Title_15::operator() (Character &model) {
        if (model.isInd) model.atk += 65;
        else model.atk += 45;
        model.attr += 75;
        model.addAllElementOUT(20);
        model.maxCrt += 5;
    }

REGIST(Title_15, QString::fromLocal8Bit("神选之英杰"));
