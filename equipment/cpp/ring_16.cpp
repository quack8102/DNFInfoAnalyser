#include "equipment/h/ring_16.h"
#include "settingdata.h"

void Ring_16::operator() (Character &model) { // 无欲：守门人的梦幻邪念
    if (model.equipName->contains(QObject::tr("幻影：守门人的黑色面具"))) {
        model.addAllElementIN(SettingData::guardELE);
    }
}

REGIST(Ring_16, QObject::tr("无欲：守门人的梦幻邪念"));
