#include "equipment/h/set_14.h"

void Set_14::operator() (Character &model) {
        if (model.setCnt->at(14) >= 2) model.entryCnt++;
        if (model.setCnt->at(14) >= 3) model.entryCnt++;
        if (model.setCnt->at(14) >= 5) model.entryCnt++;
    }

REGIST(Set_14, QString::fromLocal8Bit("命运歧路"));
