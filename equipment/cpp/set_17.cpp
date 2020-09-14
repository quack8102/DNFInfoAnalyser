#include "equipment/h/set_17.h"

void Set_17::operator() (Character &model) {
        if (model.setCnt->at(17) >= 2) model.entryCnt++;
        if (model.setCnt->at(17) >= 3) {
            model.entryCnt++;
            model.addActiveLevelOUT(100, 100, 1);
            model.addPassiveLevelOUT(100, 100, 1);
        }
    }

REGIST(Set_17, QObject::tr("破晓曦光"));
