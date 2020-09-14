#include "equipment/h/set_42.h"

void Set_42::operator() (Character &model) {
        if (model.setCnt->at(42) >= 2) model.entryCnt++;
        if (model.setCnt->at(42) >= 3) model.entryCnt++;
        if (model.setCnt->at(42) >= 5) model.entryCnt++;
    }

REGIST(Set_42, QObject::tr("最佳球手的绝杀"));
