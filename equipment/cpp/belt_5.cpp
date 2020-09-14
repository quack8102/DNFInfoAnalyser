#include "equipment/h/belt_5.h"

void Belt_5::operator() (Character &model) {
        int lv = 100, qual = 0, type = 3;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addActiveLevelOUT(1, 85, 1);
        model.addActiveLevelOUT(100, 100, 1);
        model.addPassiveLevelOUT(1, 85, 1);
        model.addPassiveLevelOUT(100, 100, 1);

        if (model.equipName->contains(QObject::tr("战无不胜上衣")) || model.isHero == true) {
            model.addAllElementIN(72);
        } else {
            model.addAllElementIN(68);
        }
    }

REGIST(Belt_5, QObject::tr("浴血奋战腰带"));
