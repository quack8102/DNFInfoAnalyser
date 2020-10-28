#ifndef MAGICSTONE_2_H
#define MAGICSTONE_2_H

#include "equipment.h"

class Magicstone_2 : public Equipment { // 时之漩涡 Magicstone: 12
  public:
    Magicstone_2() {}
	void operator() (Character &model);
};

#endif // MAGICSTONE_2_H
