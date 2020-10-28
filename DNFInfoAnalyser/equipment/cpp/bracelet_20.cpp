#include "equipment/h/bracelet_20.h"

void Bracelet_20::operator() (Character &model) {
        int lv = 85, qual = 0, type = 7;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        if (model.equipName->contains(QString::fromLocal8Bit("扭曲的异界魔石"))) {
            model.attr += 100;
        }
        model.attr += 55;
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
    }

REGIST(Bracelet_20, QString::fromLocal8Bit("精炼的毁伤魔石手环"));
