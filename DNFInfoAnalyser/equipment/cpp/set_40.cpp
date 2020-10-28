#include "equipment/h/set_40.h"

void Set_40::operator() (Character &model) {
        if (model.setCnt->at(40) >= 2) model.entryCnt++;
        if (model.setCnt->at(40) >= 3) model.entryCnt++;
        if (model.setCnt->at(40) >= 5) {
            model.entryCnt++;
            model.attr += 150;
        }
    }

REGIST(Set_40, QString::fromLocal8Bit("杀意决"));
