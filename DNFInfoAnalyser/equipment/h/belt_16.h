#ifndef BELT_16_H
#define BELT_16_H

#include "equipment.h"

class Belt_16 : public Equipment { // 逝魔之灵心腰带 Belt: 3
  public:
    Belt_16() {}
	void operator() (Character &model);
};

#endif // BELT_16_H
