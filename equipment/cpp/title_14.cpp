#include "equipment/h/title_14.h"

void Title_14::operator() (Character &model) {
        if (model.isInd) model.atk += 60;
        else model.atk += 40;
        model.attr += 70;
        model.addAllElementOUT(15);
        model.maxCrt += 5;
    }

REGIST(Title_14, QObject::tr("秘境迷踪"));
