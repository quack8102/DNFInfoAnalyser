#include "csvdataparser.h"
#include <QDebug>

LayoutData::LayoutData() :
    name(""), id(0), posx(0), posy(0), offsetx(0), offsety(0), width(0), height(0) {}

LayoutData::LayoutData(const QStringList &li) :
    name(li.value(0, "")), id(li.value(1, "0").toInt()), posx(li.value(2, "0").toInt()),
    posy(li.value(3, "0").toInt()), offsetx(li.value(4, "0").toInt()), offsety(li.value(5, "0").toInt()),
    width(li.value(6, "0").toInt()), height(li.value(7, "0").toInt()) {
    //qDebug() << name << " " << id << " " << sex << " " << synergy << endl;
}

cv::Rect LayoutData::getSelect() {
    return cv::Rect(posx + offsetx, posy + offsety, width, height);
}

ClassData::ClassData() :
    name(""), oldname(""), id(0), synergy(0), weaponType(0), STR(0), INT(0), PHY(0), IND(0), type(0) {}

ClassData::ClassData(const QStringList &li) :
    name(li.value(0, "")), oldname(li.value(1, "")), id(li.value(2, "0").toInt()), synergy(li.value(3, "0").toInt()),
    weaponType(li.value(4, "0").toInt()), STR(li.value(5, "0").toInt()), INT(li.value(6, "0").toInt()),
    PHY(li.value(7, "0").toInt()), IND(li.value(8, "0").toInt()), type(li.value(9, "0").toInt()) {
    //qDebug() << name << " " << id << " " << sex << " " << synergy << endl;
}

EquipmentData::EquipmentData() :
    name(""), id(0), setid(0) {}

EquipmentData::EquipmentData(const QStringList &li) :
    name(li.value(0, "")), id(li.value(1, "0").toInt()), setid(li.value(2, "0").toInt()) {
    //qDebug() << name << " " << id << " " << sex << " " << synergy << endl;
}

SetData::SetData() : name(""), id() {}

SetData::SetData(const QStringList &li) :
    name(li.value(0, "")), id(li.value(1, "0").toInt()) {
    //qDebug() << name << " " << id << " " << sex << " " << synergy << endl;
}

CharData::CharData() : id(0), name("") {}

CharData::CharData(const QStringList &li) :
    id(li.value(0, "0").toInt()), name(li.value(1, "")) {
    //qDebug() << name << " " << id << " " << sex << " " << synergy << endl;
}
