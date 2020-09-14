#include "equipment/h/set_49.h"

void Set_49::operator() (Character &model) {
        if (model.setCnt->at(49) >= 2) model.entryCnt++;
        if (model.setCnt->at(49) >= 3) model.entryCnt++;
    }

REGIST(Set_49, QObject::tr("江山如画"));
