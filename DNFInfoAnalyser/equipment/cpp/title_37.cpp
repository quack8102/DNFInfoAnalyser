#include "equipment/h/title_37.h"

void Title_37::operator() (Character &model) { // 穿越星空的祈愿
    model.attr += 100;
    model.atk += 65;
    model.addAllElementOUT(22);
    model.maxCrt += 6;
}

REGIST(Title_37, QString::fromLocal8Bit("穿越星空的祈愿"));