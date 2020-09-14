#include "equipment/h/title_8.h"

void Title_8::operator() (Character &model) {
        if (model.isInd) model.atk += 50;
        else model.atk += 30;
        model.attr += 60;
        model.addAllElementOUT(15);
        model.maxCrt += 5;
    }

REGIST(Title_8, QObject::tr("龙之挑战"));
