#include "equipment/h/support_17.h"
#include "settingdata.h"

void Support_17::operator() (Character &model) { // 幻影：守门人的黑色面具
    if (model.equipName->contains(QString::fromLocal8Bit("无形：守门人的灵魂甲胄"))) {
        model.addAllElementIN(SettingData::guardELE);
    }
}

REGIST(Support_17, QString::fromLocal8Bit("幻影：守门人的黑色面具"));
