#include "equipment/h/set_39.h"

void Set_39::operator() (Character &model) {
        if (model.setCnt->at(39) >= 2) model.entryCnt++;
        if (model.setCnt->at(39) >= 3) model.entryCnt++;
        if (model.setCnt->at(39) >= 5) {
            model.entryCnt++;
            if (model.isInd) model.atk += 550;
            else if (!model.isPhy) model.atk += 550;
        }
    }

REGIST(Set_39, QString::fromLocal8Bit("逝魔之力"));
