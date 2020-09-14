#ifndef MAGICSTONE_0_H
#define MAGICSTONE_0_H

#include "equipment.h"

class Magicstone_0 : public Equipment { // 军神的庇护宝石 Magicstone: 12
  public:
    Magicstone_0() {}
	void operator() (Character &model);
};

#endif // MAGICSTONE_0_H
