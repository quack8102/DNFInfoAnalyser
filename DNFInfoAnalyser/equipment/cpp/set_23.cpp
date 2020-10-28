#include "equipment/h/set_23.h"

void Set_23::operator() (Character &model) {
        if (model.setCnt->at(23) >= 2) model.entryCnt++;
        if (model.setCnt->at(23) >= 3) model.entryCnt++;
    }

REGIST(Set_23, QString::fromLocal8Bit("能量主宰"));
