#include "equipment/h/set_16.h"

void Set_16::operator() (Character &model) {
        if (model.setCnt->at(16) >= 2) model.entryCnt++;
        if (model.setCnt->at(16) >= 3) model.entryCnt++;
    }

REGIST(Set_16, QObject::tr("上古尘封术士"));
