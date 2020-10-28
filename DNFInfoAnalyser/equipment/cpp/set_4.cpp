#include "equipment/h/set_4.h"

void Set_4::operator() (Character &model) {
        if (model.setCnt->at(4) >= 2) {
            model.entryCnt++;
            model.addAllElementOUT(55);
        }
        if (model.setCnt->at(4) >= 3) model.entryCnt++;
        if (model.setCnt->at(4) >= 5) model.entryCnt++;
    }

REGIST(Set_4, QString::fromLocal8Bit("死亡阴影"));
