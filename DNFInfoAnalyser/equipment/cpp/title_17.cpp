#include "equipment/h/title_17.h"

void Title_17::operator() (Character &model) {
        model.atk += 60;
        model.attr += 80;
        model.addAllElementOUT(15);
        model.maxCrt += 5;
    }

REGIST(Title_17, QString::fromLocal8Bit("使徒降临"));
