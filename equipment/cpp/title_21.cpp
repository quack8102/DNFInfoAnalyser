#include "equipment/h/title_21.h"

void Title_21::operator() (Character &model) {
        model.atk += 40;
        model.attr += 60;
        model.LIGHT_OUT += 20;
    }

REGIST(Title_21, QObject::tr("白白海豚"));
