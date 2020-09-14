#include "equipment/h/necklace_9.h"

void Necklace_9::operator() (Character &model) {
        int lv = 85, qual = 0, type = 8;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        if (model.equipName->contains(QObject::tr("冰雪公主的结晶"))) {
            model.attr += 100;
        }
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.ICE_OUT += 30;
    }

REGIST(Necklace_9, QObject::tr("冰雪公主的霜语项链"));
