#include "equipment/h/title_32.h"

void Title_32::operator() (Character &model) { // 伊希斯的苍穹之歌
    model.attr += 60;
    model.addAllElementOUT(15);
    model.addAllElementIN(10);
}

REGIST(Title_32, QObject::tr("伊希斯的苍穹之歌"));
