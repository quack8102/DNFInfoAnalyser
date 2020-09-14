#include "equipment/h/set_8.h"

void Set_8::operator() (Character &model) {
        if (model.setCnt->at(8) >= 2) {
            model.entryCnt++;
            model.addAllElementOUT(40);
        }
        if (model.setCnt->at(8) >= 3) model.entryCnt++;
        if (model.setCnt->at(8) >= 5) model.entryCnt++;
    }

REGIST(Set_8, QObject::tr("炙炎之盛宴"));
