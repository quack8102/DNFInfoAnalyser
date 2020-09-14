#include "equipment/h/belt_20.h"

void Belt_20::operator() (Character &model) {
        int lv = 85, qual = 0, type = 3;
        if (model.isPhy) {
            if (model.armorType == 1) model.attr += 0;
            if (model.armorType == 2) model.attr += 25;
            if (model.armorType == 3) model.attr += 31;
            if (model.armorType == 4) model.attr += 28;
            if (model.armorType == 5) model.attr += 25;
        } else {
            if (model.armorType == 1) model.attr += 31;
            if (model.armorType == 2) model.attr += 25;
            if (model.armorType == 3) model.attr += 20;
            if (model.armorType == 4) model.attr += 20;
            if (model.armorType == 5) model.attr += 25;
        }
        if (model.equipName->contains(QObject::tr("禁断契约书"))) {
            model.attr += 100;
        }
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.inatk += 100;
    }

REGIST(Belt_20, QObject::tr("誓血之盟腰带"));
