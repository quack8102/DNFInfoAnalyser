#include "equipment/h/belt_23.h"

void Belt_23::operator() (Character &model) {
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
        model.attr += 165;
        if (model.equipName->contains(QString::fromLocal8Bit("全能霸域"))) {
            model.attr += 100;
        }
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Belt_23, QString::fromLocal8Bit("霸域英豪腰带"));
