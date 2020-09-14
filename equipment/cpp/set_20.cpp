#include "equipment/h/set_20.h"

void Set_20::operator() (Character &model) {
        if (model.setCnt->at(20) >= 2) model.entryCnt++;
        if (model.setCnt->at(20) >= 3) model.entryCnt++;
    }

REGIST(Set_20, QObject::tr("军神的隐秘遗产"));
