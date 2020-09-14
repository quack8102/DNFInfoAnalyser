#include "equipment/h/ring_8.h"

void Ring_8::operator() (Character &model) {
        int lv = 100, qual = -1, type = 10;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addAllElementOUT(28);
    }

REGIST(Ring_8, QObject::tr("维度粉碎戒指"));
