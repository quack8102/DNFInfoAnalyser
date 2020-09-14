#include "equipment/h/magicstone_9.h"

void Magicstone_9::operator() (Character &model) {
        int lv = 95, qual = 0, type = 12;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        if (model.equipName->contains(QObject::tr("天衍万物"))) {
            model.attr += 100;
        }
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
        model.attr += CALC::getRefoAttr(lv, qual, model.ampLV, type);

        model.addAllElementOUT(50);
    }

REGIST(Magicstone_9, QObject::tr("轮回：周而复始的时间"));
