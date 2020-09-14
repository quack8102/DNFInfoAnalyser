#include "equipment/h/set_30.h"

void Set_30::operator() (Character &model) {
        if (model.setCnt->at(30) >= 2) model.entryCnt++;
        if (model.setCnt->at(30) >= 3) model.entryCnt++;
    }

REGIST(Set_30, QObject::tr("穿透命运的呐喊"));
