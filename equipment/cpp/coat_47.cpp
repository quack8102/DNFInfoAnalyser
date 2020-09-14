#include "equipment/h/coat_47.h"

void Coat_47::operator() (Character &model) {
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
        if (model.equipName->contains(QObject::tr("聚魔漩涡"))) {
            lv += 15;
            model.attr += 100;
        }
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Coat_47, QObject::tr("魔战无双胸甲"));
