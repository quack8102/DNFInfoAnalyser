#include "equipment/h/set_32.h"

void Set_32::operator() (Character &model) {
        if (model.setCnt->at(32) >= 2) model.entryCnt++;
        if (model.setCnt->at(32) >= 3) {
            model.entryCnt++;
            model.addAllElementIN(40);
        }
    }

REGIST(Set_32, QString::fromLocal8Bit("地狱求道者"));
