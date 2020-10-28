#include "equipment/h/set_19.h"

void Set_19::operator() (Character &model) {
        if (model.setCnt->at(19) >= 2) model.entryCnt++;
        if (model.setCnt->at(19) >= 3) model.entryCnt++;
    }

REGIST(Set_19, QString::fromLocal8Bit("精灵使的权能"));
