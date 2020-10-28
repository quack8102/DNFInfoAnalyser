#include "equipment/h/set_45.h"

void Set_45::operator() (Character &model) {
        if (model.setCnt->at(45) >= 2) model.entryCnt++;
        if (model.setCnt->at(45) >= 3) model.entryCnt++;
        if (model.setCnt->at(45) >= 5) {
            model.entryCnt++;
            model.addActiveLevelOUT(50, 75, 2);
            model.addPassiveLevelOUT(50, 75, 2);
            model.addActiveLevelOUT(85, 85, 1);
            model.addPassiveLevelOUT(85, 85, 1);
        }
    }

REGIST(Set_45, QString::fromLocal8Bit("魔战无双"));
