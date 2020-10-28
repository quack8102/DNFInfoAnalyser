#include "equipment/h/set_21.h"

void Set_21::operator() (Character &model) {
    if (model.setCnt->at(21) >= 2) model.entryCnt++;
    if (model.setCnt->at(21) >= 3) {
        model.entryCnt++;
        model.minCrt += 5;
        model.maxCrt += 5;
        model.addActiveLevelIN(1, 85, 1);
        model.addActiveLevelIN(100, 100, 1);
        model.addPassiveLevelIN(1, 85, 1);
        model.addPassiveLevelIN(100, 100, 1);
    }
}

REGIST(Set_21, QString::fromLocal8Bit("灵宝：世间真理"));
