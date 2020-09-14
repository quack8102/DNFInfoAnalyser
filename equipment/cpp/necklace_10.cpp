#include "equipment/h/necklace_10.h"

void Necklace_10::operator() (Character &model) {
        int lv = 85, qual = 0, type = 8;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        if (model.equipName->contains(QObject::tr("扭曲的异界魔石"))) {
            model.attr += 100;
        }
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Necklace_10, QObject::tr("精炼的混沌魔石项链"));
