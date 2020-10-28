#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "character.h"
#include "attrcalculator.h"
#include "factory.h"
#include <QString>

class Equipment {
  public:
    virtual void operator() (Character &model) = 0;
    virtual ~Equipment() {}
};

#define REGIST(CLASS, NAME) Registrar<Equipment, CLASS> __##CLASS(NAME)

#endif // EQUIPMENT_H
