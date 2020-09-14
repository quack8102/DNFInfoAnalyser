#include "equipment/h/title_16.h"

void Title_16::operator() (Character &model) {
        model.attr += 60;
        model.addAllElementOUT(15);
        model.addAllElementIN(10);
    }

REGIST(Title_16, QObject::tr("超越极限者"));
