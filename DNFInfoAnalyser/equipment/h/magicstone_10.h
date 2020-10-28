#ifndef MAGICSTONE_10_H
#define MAGICSTONE_10_H

#include "equipment.h"

class Magicstone_10 : public Equipment { // 赤鬼的次元石 Magicstone: 12
  public:
    Magicstone_10() {}
	void operator() (Character &model);
};

#endif // MAGICSTONE_10_H
