#include "equipment/h/set_3.h"

void Set_3::operator() (Character &model) {
        if (model.setCnt->at(3) >= 2) model.entryCnt++;
        if (model.setCnt->at(3) >= 3) model.entryCnt++;
        if (model.setCnt->at(3) >= 5) {
            model.entryCnt++;
            model.maxCrt += 10;
        }
    }

REGIST(Set_3, QString::fromLocal8Bit("天堂舞姬"));
