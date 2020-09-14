#include "equipment/h/set_27.h"

void Set_27::operator() (Character &model) {
        if (model.setCnt->at(27) >= 2) model.entryCnt++;
        if (model.setCnt->at(27) >= 3) model.entryCnt++;
    }

REGIST(Set_27, QObject::tr("吞噬愤怒"));
