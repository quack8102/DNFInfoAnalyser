#include "equipment/h/coat_42.h"

void Coat_42::operator() (Character &model) {
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
        model.attr += 50;
        if (model.equipName->contains(QObject::tr("杀戮之决"))) {
            model.attr += 100;
        }
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Coat_42, QObject::tr("暗魅之影上衣"));
