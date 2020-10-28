#include "equipment/h/coat_40.h"

void Coat_40::operator() (Character &model) {
    int lv = 100, qual = 0, type = 1;
    if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
    else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
    model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);

    model.reformCnt++;
    model.attr += 25 * model.reformLV;
}

REGIST(Coat_40, QString::fromLocal8Bit("轮回：黑暗幽灵紫杉胸甲"));
