#include "equipment/h/set_46.h"

void Set_46::operator() (Character &model) {
        if (model.setCnt->at(46) >= 2) model.entryCnt++;
        if (model.setCnt->at(46) >= 3) model.entryCnt++;
        if (model.setCnt->at(46) >= 5) {
            model.entryCnt++;
            model.atk += 300;
            model.attr += 220;
        }
    }

REGIST(Set_46, QObject::tr("霸域英豪"));
