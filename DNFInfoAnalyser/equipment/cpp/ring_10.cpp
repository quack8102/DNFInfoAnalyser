#include "equipment/h/ring_10.h"

void Ring_10::operator() (Character &model) {
        int lv = 85, qual = 0, type = 10;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        if (model.equipName->contains(QString::fromLocal8Bit("扭曲的异界魔石"))) {
            model.attr += 100;
        }
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Ring_10, QString::fromLocal8Bit("精炼的遗忘魔石戒指"));
