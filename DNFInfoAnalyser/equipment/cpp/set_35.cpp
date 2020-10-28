#include "equipment/h/set_35.h"

void Set_35::operator() (Character &model) {
        if (model.setCnt->at(35) >= 2) model.entryCnt++;
        if (model.setCnt->at(35) >= 3) model.entryCnt++;
    }

REGIST(Set_35, QString::fromLocal8Bit("悲剧的残骸"));
