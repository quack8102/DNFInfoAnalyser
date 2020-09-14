#include "equipment/h/set_47.h"

void Set_47::operator() (Character &model) {
        if (model.setCnt->at(47) >= 2) model.entryCnt++;
        if (model.setCnt->at(47) >= 3) {
            model.entryCnt++;
            model.ICE_OUT += 50;
        }
    }

REGIST(Set_47, QObject::tr("冰雪公主的霜语首饰"));
