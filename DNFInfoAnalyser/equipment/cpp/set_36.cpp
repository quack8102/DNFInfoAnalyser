#include "equipment/h/set_36.h"

void Set_36::operator() (Character &model) {
        if (model.equipName->contains(QString::fromLocal8Bit("轮回：黑暗幽灵紫杉胸甲"))) {
            if (model.setCnt->at(36) >= 3) {
                model.attr += 200;
            }
            if (model.setCnt->at(36) >= 5) {
                model.attr += 200;
            }
        }
        if (model.setCnt->at(36) >= 2) model.entryCnt++;
        if (model.setCnt->at(36) >= 3) model.entryCnt++;
        if (model.setCnt->at(36) >= 5) model.entryCnt++;
    }

REGIST(Set_36, QString::fromLocal8Bit("堕落的黑暗之力"));
