#include "equipment/h/title_22.h"

void Title_22::operator() (Character &model) {
        model.atk += 40;
        model.attr += 60;
        model.DARK_OUT += 20;
    }

REGIST(Title_22, QString::fromLocal8Bit("墨墨海豚"));
