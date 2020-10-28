#include "equipment/h/set_7.h"

void Set_7::operator() (Character &model) {
        if (model.setCnt->at(7) >= 2) model.entryCnt++;
        if (model.setCnt->at(7) >= 3) {
            model.entryCnt++;
            model.addAllElementOUT(60);
        }
        if (model.setCnt->at(7) >= 5) model.entryCnt++;
    }

REGIST(Set_7, QString::fromLocal8Bit("贫瘠沙漠的遗产"));
