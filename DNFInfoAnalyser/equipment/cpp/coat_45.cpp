#include "equipment/h/coat_45.h"

void Coat_45::operator() (Character &model) {
        int lv = 85, qual = 0, type = 1;
        if (model.isPhy) {
            if (model.armorType == 1) model.attr += 0;
            if (model.armorType == 2) model.attr += 43;
            if (model.armorType == 3) model.attr += 51;
            if (model.armorType == 4) model.attr += 46;
            if (model.armorType == 5) model.attr += 43;
        } else {
            if (model.armorType == 1) model.attr += 51;
            if (model.armorType == 2) model.attr += 43;
            if (model.armorType == 3) model.attr += 34;
            if (model.armorType == 4) model.attr += 34;
            if (model.armorType == 5) model.attr += 43;
        }
        model.attr += 220;
        if (model.equipName->contains(QString::fromLocal8Bit("禁断契约书"))) {
            model.attr += 100;
        }
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Coat_45, QString::fromLocal8Bit("誓血之盟铠甲"));
