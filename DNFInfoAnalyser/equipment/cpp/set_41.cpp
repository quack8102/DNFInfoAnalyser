#include "equipment/h/set_41.h"

void Set_41::operator() (Character &model) {
        if (model.setCnt->at(41) >= 2) model.entryCnt++;
        if (model.setCnt->at(41) >= 3) model.entryCnt++;
        if (model.setCnt->at(41) >= 5) {
            model.entryCnt++;
            model.addAllElementIN(10);
        }
    }

REGIST(Set_41, QString::fromLocal8Bit("天御之灾"));
