#include "equipment/h/set_13.h"

void Set_13::operator() (Character &model) {
        if (model.setCnt->at(13) >= 2) model.entryCnt++;
        if (model.setCnt->at(13) >= 3) model.entryCnt++;
        if (model.setCnt->at(13) >= 5) model.entryCnt++;
    }

REGIST(Set_13, QObject::tr("永恒不息之路"));
