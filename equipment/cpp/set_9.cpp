#include "equipment/h/set_9.h"

void Set_9::operator() (Character &model) {
        if (model.setCnt->at(9) >= 2) model.entryCnt++;
        if (model.setCnt->at(9) >= 3) model.entryCnt++;
        if (model.setCnt->at(9) >= 5) model.entryCnt++;
    }

REGIST(Set_9, QObject::tr("擎天战甲"));
