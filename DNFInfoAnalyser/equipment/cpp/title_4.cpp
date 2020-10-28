#include "equipment/h/title_4.h"

void Title_4::operator() (Character &model) {
        model.attr += 55;
        model.addAllElementOUT(18);
        model.addAllElementIN(10);
    }

REGIST(Title_4, QString::fromLocal8Bit("骑士王的荣耀"));
