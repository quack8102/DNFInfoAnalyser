#include "equipment/h/set_48.h"

void Set_48::operator() (Character &model) {
        if (model.setCnt->at(48) >= 2) model.entryCnt++;
        if (model.setCnt->at(48) >= 3) {
            model.entryCnt++;
            model.addAllElementOUT(18);
        }
    }

REGIST(Set_48, QObject::tr("精炼的异界魔石首饰"));
