#include "equipment/h/title_6.h"

void Title_6::operator() (Character &model) {
        model.attr += 55;
        model.addAllElementOUT(15);
        model.addAllElementIN(10);
    }

REGIST(Title_6, QObject::tr("最强战皇"));
