#include "equipment/h/set_11.h"

void Set_11::operator() (Character &model) {
        if (model.setCnt->at(11) >= 2) model.entryCnt++;
        if (model.setCnt->at(11) >= 3) model.entryCnt++;
        if (model.setCnt->at(11) >= 5) model.entryCnt++;
    }

REGIST(Set_11, QObject::tr("传奇铁匠-封神"));
