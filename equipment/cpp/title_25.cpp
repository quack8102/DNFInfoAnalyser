#include "equipment/h/title_25.h"

void Title_25::operator() (Character &model) {
        model.attr += 55;
        model.addAllElementOUT(10);
        model.maxCrt += 5;
    }

REGIST(Title_25, QObject::tr("万灵之尊"));
