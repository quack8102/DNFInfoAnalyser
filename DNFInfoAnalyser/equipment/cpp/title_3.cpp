#include "equipment/h/title_3.h"

void Title_3::operator() (Character &model) {
        if (model.isInd) model.atk += 50;
        else model.atk += 30;
        model.attr += 60;
        model.addAllElementOUT(15);
        model.maxCrt += 5;
    }

REGIST(Title_3, QString::fromLocal8Bit("桃园结义[义]"));
