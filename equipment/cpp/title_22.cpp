#include "equipment/h/title_22.h"

void Title_22::operator() (Character &model) {
        model.atk += 40;
        model.attr += 60;
        model.DARK_OUT += 20;
    }

REGIST(Title_22, QObject::tr("墨墨海豚"));
