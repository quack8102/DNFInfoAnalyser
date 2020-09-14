#include "equipment/h/set_26.h"

void Set_26::operator() (Character &model) {
        if (model.setCnt->at(26) >= 2) model.entryCnt++;
        if (model.setCnt->at(26) >= 3) model.entryCnt++;
    }

REGIST(Set_26, QObject::tr("坎坷命运"));
