#include "equipment/h/set_34.h"

void Set_34::operator() (Character &model) {
        if (model.setCnt->at(34) >= 2) model.entryCnt++;
        if (model.setCnt->at(34) >= 3) model.entryCnt++;
    }

REGIST(Set_34, QObject::tr("天命无常"));
