#include "equipment/h/title_31.h"

void Title_31::operator() (Character &model) { // 卢克的创生之灵
    model.attr += 60;
    model.addAllElementOUT(15);
    model.addAllElementIN(10);
}

REGIST(Title_31, QObject::tr("卢克的创生之灵"));
