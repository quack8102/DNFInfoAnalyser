#include "equipment/h/set_29.h"

void Set_29::operator() (Character &model) {
        if (model.setCnt->at(29) >= 2) model.entryCnt++;
        if (model.setCnt->at(29) >= 3) model.entryCnt++;
    }

REGIST(Set_29, QString::fromLocal8Bit("时空旅行者"));
