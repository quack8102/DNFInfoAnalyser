#include "equipment/h/pants_32.h"
#include "settingdata.h"

void Pants_32::operator() (Character &model) { // 无形：守门人的灵魂甲胄
    if (model.equipName->contains(QObject::tr("无欲：守门人的梦幻邪念"))) {
        model.addAllElementIN(SettingData::guardELE);
    }
}

REGIST(Pants_32, QObject::tr("无形：守门人的灵魂甲胄"));
