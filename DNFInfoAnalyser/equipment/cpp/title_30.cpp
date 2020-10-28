#include "equipment/h/title_30.h"

void Title_30::operator() (Character &model) { // 安徒恩的炎魔之魂
    model.attr += 60;
    model.addAllElementOUT(15);
    model.addAllElementIN(10);
}

REGIST(Title_30, QString::fromLocal8Bit("安徒恩的炎魔之魂"));
