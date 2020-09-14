#include "equipment/h/set_38.h"

void Set_38::operator() (Character &model) {
        if (model.equipName->contains(QObject::tr("轮回：腐蚀之黑色十字耳环"))) {
            if (model.setCnt->at(38) >= 3) {
                model.attr += 200;
            }
        }
        if (model.setCnt->at(38) >= 2) model.entryCnt++;
        if (model.setCnt->at(38) >= 3) model.entryCnt++;
    }

REGIST(Set_38, QObject::tr("暗之腐蚀"));
