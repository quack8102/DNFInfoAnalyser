#include "equipment/h/title_24.h"

void Title_24::operator() (Character &model) {
        if (!model.isPhy) model.attr += 50;
        model.addAllElementOUT(7);
        model.maxCrt += 5;
    }

REGIST(Title_24, QString::fromLocal8Bit("瑞灵天狩-慧"));
