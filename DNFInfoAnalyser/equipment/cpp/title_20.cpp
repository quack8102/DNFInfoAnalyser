#include "equipment/h/title_20.h"

void Title_20::operator() (Character &model) {
        model.atk += 40;
        model.attr += 60;
        model.FIRE_OUT += 20;
    }

REGIST(Title_20, QString::fromLocal8Bit("粉粉海豚"));
