#include "equipment/h/shoes_28.h"

void Shoes_28::operator() (Character &model) { // 无言之罪恶
    int lv = 100, qual = 0, type = 4;
    if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
    else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
    model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
    model.reformCnt++;
}

REGIST(Shoes_28, QObject::tr("无言之罪恶"));
