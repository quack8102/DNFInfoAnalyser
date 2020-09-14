#include "equipment/h/title_10.h"

void Title_10::operator() (Character &model) {
        model.attr += 55;
        model.addAllElementOUT(15);
        model.addAllElementIN(10);
    }

REGIST(Title_10, QObject::tr("海洋霸主"));
