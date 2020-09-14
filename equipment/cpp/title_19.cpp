#include "equipment/h/title_19.h"

void Title_19::operator() (Character &model) {
        model.atk += 40;
        model.attr += 60;
        model.ICE_OUT += 20;
    }

REGIST(Title_19, QObject::tr("蓝蓝海豚"));
