#include "equipment/h/set_12.h"

void Set_12::operator() (Character &model) {
        if (model.setCnt->at(12) >= 2) model.entryCnt++;
        if (model.setCnt->at(12) >= 3) model.entryCnt++;
        if (model.setCnt->at(12) >= 5) model.entryCnt++;
    }

REGIST(Set_12, QString::fromLocal8Bit("荆棘漫天"));
