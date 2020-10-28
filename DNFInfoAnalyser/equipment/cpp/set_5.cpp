#include "equipment/h/set_5.h"

void Set_5::operator() (Character &model) {
        if (model.setCnt->at(5) >= 2) {
            model.entryCnt++;
            model.addAllElementOUT(52);
        }
        if (model.setCnt->at(5) >= 3) {
            model.entryCnt++;
            model.addAllElementOUT(62);
        }
        if (model.setCnt->at(5) >= 5) model.entryCnt++;
    }

REGIST(Set_5, QString::fromLocal8Bit("皇家裁决者宣言"));
