#include "equipment/h/bracelet_17.h"

void Bracelet_17::operator() (Character &model) {
        int lv = 100, qual = -1, type = 7;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(28);
    }

REGIST(Bracelet_17, QObject::tr("时空：维度冲击臂环"));
