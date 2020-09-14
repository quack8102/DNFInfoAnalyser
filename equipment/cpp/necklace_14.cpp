#include "equipment/h/necklace_14.h"

void Necklace_14::operator() (Character &model) {
        int lv = 100, qual = 0, type = 8;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

        model.addAllElementOUT(119);
    }

REGIST(Necklace_14, QObject::tr("百变千蛛"));
