#include "equipment/h/set_15.h"

void Set_15::operator() (Character &model) {
        if (model.setCnt->at(15) >= 2) model.entryCnt++;
        if (model.setCnt->at(15) >= 3) model.entryCnt++;
        if (model.setCnt->at(15) >= 5) {
            model.entryCnt++;
            model.addAllElementOUT(64);
        }
    }

REGIST(Set_15, QString::fromLocal8Bit("大自然的呼吸"));
