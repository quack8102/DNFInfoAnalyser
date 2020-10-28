#include "equipment/h/set_50.h"

void Set_50::operator() (Character &model) {
        if (model.setCnt->at(50) >= 2) model.entryCnt++;
        if (model.setCnt->at(50) >= 3) model.entryCnt++;
    }

REGIST(Set_50, QString::fromLocal8Bit("万物的生灭"));
