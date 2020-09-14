#ifndef MAGICSTONE_12_H
#define MAGICSTONE_12_H

#include "equipment.h"

class Magicstone_12 : public Equipment { // 冰雪公主的结晶 Magicstone: 12
  public:
    Magicstone_12() {}
	void operator() (Character &model);
};

#endif // MAGICSTONE_12_H
