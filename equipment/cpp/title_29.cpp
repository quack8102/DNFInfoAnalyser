#include "equipment/h/title_29.h"

void Title_29::operator() (Character &model) { // 希洛克的悲鸣
    model.attr += 60;
    model.addAllElementOUT(15);
    model.addAllElementIN(10);
}

REGIST(Title_29, QObject::tr("希洛克的悲鸣"));
