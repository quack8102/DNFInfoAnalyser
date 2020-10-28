#include "equipment/h/set_28.h"

void Set_28::operator() (Character &model) {
    if (model.setCnt->at(28) >= 2) model.entryCnt++;
    if (model.setCnt->at(28) >= 3) {
		model.minCrt += 10;
		model.maxCrt += 10;
		model.entryCnt++;
	}
}

REGIST(Set_28, QString::fromLocal8Bit("黑魔法探求者"));
