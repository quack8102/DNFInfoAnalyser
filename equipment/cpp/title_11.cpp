#include "equipment/h/title_11.h"

void Title_11::operator() (Character &model) {
        if (model.isInd) model.atk += 50;
        else model.atk += 30;
        model.attr += 70;
        model.addAllElementOUT(15);
        model.maxCrt += 5;
    }

REGIST(Title_11, QObject::tr("兽人守护神"));
