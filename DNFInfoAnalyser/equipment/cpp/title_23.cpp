#include "equipment/h/title_23.h"

void Title_23::operator() (Character &model) {
        if (model.isPhy) model.attr += 50;
        model.addAllElementOUT(7);
        model.maxCrt += 5;
    }

REGIST(Title_23, QString::fromLocal8Bit("瑞灵天狩-威"));
