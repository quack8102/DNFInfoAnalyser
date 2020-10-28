#include "equipment/h/set_25.h"

void Set_25::operator() (Character &model) {
        if (model.setCnt->at(25) >= 2) model.entryCnt++;
        if (model.setCnt->at(25) >= 3) {
            model.entryCnt++;
            model.addAllElementOUT(32);
        }
    }

REGIST(Set_25, QString::fromLocal8Bit("圣者的黄昏"));
