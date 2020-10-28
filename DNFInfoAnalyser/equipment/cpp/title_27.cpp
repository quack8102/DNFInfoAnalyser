#include "equipment/h/title_27.h"

void Title_27::operator() (Character &model) { // 安徒恩的烈焰
    model.attr += 60;
    model.addAllElementOUT(15);
    model.addAllElementIN(10);
}

REGIST(Title_27, QString::fromLocal8Bit("安徒恩的烈焰"));
