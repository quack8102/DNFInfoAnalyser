#include "equipment/h/set_33.h"

void Set_33::operator() (Character &model) {
        if (model.setCnt->at(33) >= 2) model.entryCnt++;
        if (model.setCnt->at(33) >= 3) model.entryCnt++;
    }

REGIST(Set_33, QObject::tr("次元旅行者"));
