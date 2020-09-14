#include "equipment/h/title_18.h"

void Title_18::operator() (Character &model) {
        model.atk += 65;
        model.attr += 90;
        model.addAllElementOUT(20);
        model.maxCrt += 6;
    }

REGIST(Title_18, QObject::tr("伟大的意志"));
