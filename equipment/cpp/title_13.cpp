#include "equipment/h/title_13.h"

void Title_13::operator() (Character &model) {
        model.attr += 55;
        model.addAllElementOUT(15);
        model.addAllElementIN(10);
    }

REGIST(Title_13, QObject::tr("神之试炼的奖赏"));
