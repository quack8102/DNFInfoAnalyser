#include "equipment/h/set_2.h"

void Set_2::operator() (Character &model) {
        if (model.setCnt->at(2) >= 2) model.entryCnt++;
        if (model.setCnt->at(2) >= 3) model.entryCnt++;
        if (model.setCnt->at(2) >= 5) {
            model.entryCnt++;
            model.addActiveLevelOUT(1, 85, 2);
            model.addActiveLevelOUT(100, 100, 2);
            model.addPassiveLevelOUT(1, 85, 2);
            model.addPassiveLevelOUT(100, 100, 2);
        }
    }

REGIST(Set_2, QString::fromLocal8Bit("遗忘魔法师的馈赠"));
