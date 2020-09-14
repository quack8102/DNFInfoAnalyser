#include "equipment/h/set_6.h"

void Set_6::operator() (Character &model) {
        if (model.setCnt->at(6) >= 2) model.entryCnt++;
        if (model.setCnt->at(6) >= 3) {
            model.entryCnt++;
            model.addAllElementOUT(24);
        }
        if (model.setCnt->at(6) >= 5) model.entryCnt++;
    }

REGIST(Set_6, QObject::tr("龙血玄黄"));
