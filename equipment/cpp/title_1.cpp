#include "equipment/h/title_1.h"

void Title_1::operator() (Character &model) {
        if (model.isInd) model.atk += 50;
        else model.atk += 30;
        model.addAllElementOUT(18);
        model.maxCrt += 10;
    }

REGIST(Title_1, QObject::tr("圣殿之巅"));
