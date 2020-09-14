#include "equipment/h/set_1.h"

void Set_1::operator() (Character &model) {
        if (model.setCnt->at(1) >= 2) model.entryCnt++;
        if (model.setCnt->at(1) >= 3) model.entryCnt++;
        if (model.setCnt->at(1) >= 5) model.entryCnt++;
    }

REGIST(Set_1, QObject::tr("古代祭祀的神圣仪式"));
