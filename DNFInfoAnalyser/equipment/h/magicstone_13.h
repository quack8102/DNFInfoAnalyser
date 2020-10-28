#ifndef MAGICSTONE_13_H
#define MAGICSTONE_13_H

#include "equipment.h"

class Magicstone_13 : public Equipment { // 扭曲的异界魔石 Magicstone: 12
  public:
    Magicstone_13() {}
	void operator() (Character &model);
};

#endif // MAGICSTONE_13_H
