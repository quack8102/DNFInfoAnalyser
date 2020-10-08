#ifndef CSVDATAPARSER_H
#define CSVDATAPARSER_H

#include <QString>
#include <QStringList>
#include <opencv2/core/core.hpp>

class LayoutData {
  public:
    const QString name;
    const int id, posx, posy, offsetx, offsety, width, height;
    LayoutData();
    LayoutData(const QStringList &li);
    cv::Rect getSelect();
};

class ClassData {
  public:
    const QString name, oldname;
    const int id, synergy, weaponType, STR, INT, PHY, IND, type;
    ClassData();
    ClassData(const QStringList &li);
};

class EquipmentData {
  public:
    const QString name;
    const int id, setid;
    EquipmentData();
    EquipmentData(const QStringList &li);
};

class SetData {
  public:
    const QString name;
    const int id;
    SetData();
    SetData(const QStringList &li);
};

class CharData {
  public:
    const int id;
    const QString name;
    CharData();
    CharData(const QStringList &li);
};

#endif // CSVDATAPARSER_H
