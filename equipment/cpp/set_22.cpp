#include "equipment/h/set_22.h"

void Set_22::operator() (Character &model) {
        if (model.setCnt->at(22) >= 2) model.entryCnt++;
        if (model.setCnt->at(22) >= 3) model.entryCnt++;
    }

REGIST(Set_22, QObject::tr("时间战争的残骸"));
