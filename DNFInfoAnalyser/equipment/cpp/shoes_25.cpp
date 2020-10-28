#include "equipment/h/shoes_25.h"

void Shoes_25::operator() (Character &model) {
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
        model.attr += 110;
        if (model.equipName->contains(QString::fromLocal8Bit("百变千蛛"))) {
            model.attr += 100;
        }
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.addActiveLevelOUT(48, 48, 1);
        model.addPassiveLevelOUT(48, 48, 1);
    }

REGIST(Shoes_25, QString::fromLocal8Bit("千蛛碎影之利齿战靴"));
