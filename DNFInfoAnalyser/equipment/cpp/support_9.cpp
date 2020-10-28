#include "equipment/h/support_9.h"

void Support_9::operator() (Character &model) {
        int lv = 95, qual = 0, type = 9;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        if (model.equipName->contains(QString::fromLocal8Bit("天衍万物"))) {
            model.attr += 100;
        }
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);
        model.attr += CALC::getRefoAttr(lv, qual, model.ampLV, type);

        model.addActiveLevelOUT(1, 85, 1);
        model.addPassiveLevelOUT(1, 85, 1);
    }

REGIST(Support_9, QString::fromLocal8Bit("循环：无尽的诞生"));
