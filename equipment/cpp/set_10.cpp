#include "equipment/h/set_10.h"

void Set_10::operator() (Character &model) {
        if (model.setCnt->at(10) >= 2) model.entryCnt++;
        if (model.setCnt->at(10) >= 3) {
            model.entryCnt++;
            model.addAllElementOUT(66);
            model.addActiveLevelOUT(1, 85, 1);
            model.addActiveLevelOUT(100, 100, 1);
            model.addPassiveLevelOUT(1, 85, 1);
            model.addPassiveLevelOUT(100, 100, 1);
        }
        if (model.setCnt->at(10) >= 5) model.entryCnt++;
    }

REGIST(Set_10, QObject::tr("噩梦：地狱之路"));
