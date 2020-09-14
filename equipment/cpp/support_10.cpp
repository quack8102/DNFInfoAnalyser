#include "equipment/h/support_10.h"

void Support_10::operator() (Character &model) {
        int lv = 100, qual = 0, type = 9;
        if (model.isPhy) model.attr += CALC::getBaseSTR(lv, qual, type, model.armorType);
        else model.attr += CALC::getBaseINT(lv, qual, type, model.armorType);

        model.addAllElementIN(8 * model.reformLV);
        if (model.reformLV >= 1) {
            model.addActiveLevelIN(1, 85, 2);
            model.addActiveLevelIN(100, 100, 2);
            model.addPassiveLevelIN(1, 85, 2);
            model.addPassiveLevelIN(100, 100, 2);
        }
        model.reformCnt++;
    }

REGIST(Support_10, QObject::tr("青面修罗的面具"));
