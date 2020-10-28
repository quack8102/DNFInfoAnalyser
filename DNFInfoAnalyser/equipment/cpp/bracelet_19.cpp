#include "equipment/h/bracelet_19.h"

void Bracelet_19::operator() (Character &model) {
        int lv = 85, qual = 0, type = 7;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        if (model.equipName->contains(QString::fromLocal8Bit("冰雪公主的结晶"))) {
            model.attr += 100;
        }
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        model.ICE_OUT += 22;
    }

REGIST(Bracelet_19, QString::fromLocal8Bit("冰雪公主的霜语手镯"));
