#include "equipment/h/set_31.h"

void Set_31::operator() (Character &model) {
    if (model.setCnt->at(31) >= 2) {
        model.addAllElementOUT(25);
        model.entryCnt++;
    }
    if (model.setCnt->at(31) >= 3)
        model.entryCnt++;
}

REGIST(Set_31, QObject::tr("狂乱追随者"));
