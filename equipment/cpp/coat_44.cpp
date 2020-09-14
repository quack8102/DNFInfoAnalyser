#include "equipment/h/coat_44.h"

void Coat_44::operator() (Character &model) {
        int lv = 85, qual = 0, type = 1;
        if (model.isPhy) {
            if (model.armorType == 1) model.attr += 0;
            if (model.armorType == 2) model.attr += 42;
            if (model.armorType == 3) model.attr += 50;
            if (model.armorType == 4) model.attr += 46;
            if (model.armorType == 5) model.attr += 42;
        } else {
            if (model.armorType == 1) model.attr += 50;
            if (model.armorType == 2) model.attr += 42;
            if (model.armorType == 3) model.attr += 34;
            if (model.armorType == 4) model.attr += 34;
            if (model.armorType == 5) model.attr += 42;
        }
        model.attr += 94;
        if (model.equipName->contains(QObject::tr("最佳球手之球"))) {
            model.attr += 100;
        }
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.atk += 149;
    }

REGIST(Coat_44, QObject::tr("最佳球手的暴走战衣"));
