#include "equipment/h/neck_19.h"

void Neck_19::operator() (Character &model) {
        int lv = 85, qual = 0, type = 0;
        if (model.isPhy) {
            if (model.armorType == 1) model.attr += 0;
            if (model.armorType == 2) model.attr += 34;
            if (model.armorType == 3) model.attr += 41;
            if (model.armorType == 4) model.attr += 37;
            if (model.armorType == 5) model.attr += 34;
        } else {
            if (model.armorType == 1) model.attr += 41;
            if (model.armorType == 2) model.attr += 34;
            if (model.armorType == 3) model.attr += 28;
            if (model.armorType == 4) model.attr += 28;
            if (model.armorType == 5) model.attr += 34;
        }
        model.attr += 330;
        if (model.equipName->contains(QObject::tr("最佳球手之球"))) {
            model.attr += 100;
        }
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Neck_19, QObject::tr("最佳球手的反击护具"));
