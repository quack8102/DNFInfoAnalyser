#include "equipment/h/set_18.h"

void Set_18::operator() (Character &model) {
        if (model.setCnt->at(18) >= 2) {
            model.entryCnt++;
            model.addAllElementOUT(77);
            model.atk += 77;
        }
        if (model.setCnt->at(18) >= 3) model.entryCnt++;
    }

REGIST(Set_18, QString::fromLocal8Bit("幸运三角"));
