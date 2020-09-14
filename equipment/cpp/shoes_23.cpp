#include "equipment/h/shoes_23.h"

void Shoes_23::operator() (Character &model) {
        int lv = 85, qual = 0, type = 4;
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
        if (model.equipName->contains(QObject::tr("最佳球手之球"))) {
            model.attr += 100;
        }
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Shoes_23, QObject::tr("最佳球手的逆袭跑鞋"));
