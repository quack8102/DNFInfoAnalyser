#include "equipment/h/set_24.h"

void Set_24::operator() (Character &model) {
    if (model.setCnt->at(24) >= 2) {
        model.entryCnt++;
        model.addActiveLevelIN(1, 48, 2);
        model.addPassiveLevelIN(1, 48, 2);
    }
    if (model.setCnt->at(24) >= 3) {
        model.entryCnt++;
        model.addActiveLevelIN(60, 80, 2);
        model.addPassiveLevelIN(60, 80, 2);
        model.addActiveLevelIN(50, 50, 1);
        model.addPassiveLevelIN(50, 50, 1);
        model.addActiveLevelIN(85, 85, 1);
        model.addPassiveLevelIN(85, 85, 1);
        model.addActiveLevelIN(100, 100, 1);
        model.addPassiveLevelIN(100, 100, 1);
    }
}

REGIST(Set_24, QObject::tr("深渊窥视者"));
