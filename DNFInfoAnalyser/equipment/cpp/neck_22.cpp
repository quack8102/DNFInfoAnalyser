﻿#include "equipment/h/neck_22.h"

void Neck_22::operator() (Character &model) {
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
        if (model.equipName->contains(QString::fromLocal8Bit("聚魔漩涡"))) {
            lv += 15;
            model.attr += 100;
        }
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addActiveLevelOUT(30, 48, 2);
        model.addPassiveLevelOUT(30, 48, 2);
    }

REGIST(Neck_22, QString::fromLocal8Bit("魔战无双肩甲"));
