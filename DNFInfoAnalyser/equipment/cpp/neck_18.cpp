﻿#include "equipment/h/neck_18.h"

void Neck_18::operator() (Character &model) {
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
        if (model.equipName->contains(QString::fromLocal8Bit("天御万物"))) {
            model.attr += 100;
        }
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.atk += 74;
        model.DARK_OUT += 24;
    }

REGIST(Neck_18, QString::fromLocal8Bit("天御虫噬战甲"));
