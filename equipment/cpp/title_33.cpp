#include "equipment/h/title_33.h"

void Title_33::operator() (Character &model) { // 希洛克的无形之心
    model.attr += 60;
    model.addAllElementOUT(15);
    model.addAllElementIN(10);
}

REGIST(Title_33, QObject::tr("希洛克的无形之心"));
