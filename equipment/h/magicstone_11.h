#ifndef MAGICSTONE_11_H
#define MAGICSTONE_11_H

#include "equipment.h"

class Magicstone_11 : public Equipment { // 江山如故 Magicstone: 12
  public:
    Magicstone_11() {}
	void operator() (Character &model);
};

#endif // MAGICSTONE_11_H
