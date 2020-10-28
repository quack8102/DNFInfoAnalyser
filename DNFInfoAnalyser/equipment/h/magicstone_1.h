#ifndef MAGICSTONE_1_H
#define MAGICSTONE_1_H

#include "equipment.h"

class Magicstone_1 : public Equipment { // 智慧之地 Magicstone: 12
  public:
    Magicstone_1() {}
	void operator() (Character &model);
};

#endif // MAGICSTONE_1_H
