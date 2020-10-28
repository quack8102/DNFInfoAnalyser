#include "equipment/h/title_0.h"

void Title_0::operator() (Character &model) {
        model.attr += 38;
        model.addAllElementOUT(18);
        model.maxCrt += 10;
    }

REGIST(Title_0, QString::fromLocal8Bit("魔女幻想"));
