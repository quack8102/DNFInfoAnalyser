#include "equipment/h/set_43.h"

void Set_43::operator() (Character &model) {
        if (model.setCnt->at(43) >= 2) model.entryCnt++;
        if (model.setCnt->at(43) >= 3) model.entryCnt++;
        if (model.setCnt->at(43) >= 5) model.entryCnt++;
    }

REGIST(Set_43, QObject::tr("誓血之盟"));
