#include "equipment/h/set_37.h"

void Set_37::operator() (Character &model) {
        if (model.equipName->contains(QObject::tr("轮回：维度冲击臂环"))) {
            if (model.setCnt->at(37) >= 3) {
                model.attr += 200;
            }
        }
        if (model.setCnt->at(37) >= 2) model.entryCnt++;
        if (model.setCnt->at(37) >= 3) model.entryCnt++;
    }

REGIST(Set_37, QObject::tr("维度崩坏"));
