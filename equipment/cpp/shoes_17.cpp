#include "equipment/h/shoes_17.h"

void Shoes_17::operator() (Character &model) {
        int lv = 100, qual = 0, type = 4;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);
        model.attr += CALC::getMasterAttr(lv, qual, model.ampLV, type);
        model.attr += CALC::getAmpAttr(lv, qual, model.ampLV);

        if (model.equipName->contains(QObject::tr("命运反抗者"))) {
            model.addAllElementIN(24);
        } else if (model.setCnt->at(34) >= 2) {
            model.addAllElementIN(20);
        }
    }

REGIST(Shoes_17, QObject::tr("悲喜交加"));
