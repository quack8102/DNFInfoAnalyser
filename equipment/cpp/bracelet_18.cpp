#include "equipment/h/bracelet_18.h"

void Bracelet_18::operator() (Character &model) {
    int lv = 100, qual = 0, type = 7;
    if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
    else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

    model.addAllElementOUT(28);
    model.reformCnt++;
    model.attr += 25 * model.reformLV;
}

REGIST(Bracelet_18, QObject::tr("轮回：维度冲击臂环"));
