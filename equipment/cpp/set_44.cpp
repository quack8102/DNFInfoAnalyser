#include "equipment/h/set_44.h"

void Set_44::operator() (Character &model) {
        if (model.setCnt->at(44) >= 2) model.entryCnt++;
        if (model.setCnt->at(44) >= 3) model.entryCnt++;
        if (model.setCnt->at(44) >= 5) model.entryCnt++;
    }

REGIST(Set_44, QObject::tr("千蛛碎影"));
