#ifndef MAGICSTONE_6_H
#define MAGICSTONE_6_H

#include "equipment.h"

class Magicstone_6 : public Equipment { // 寂寞的呼喊 Magicstone: 12
  public:
    Magicstone_6() {}
	void operator() (Character &model);
};

#endif // MAGICSTONE_6_H
