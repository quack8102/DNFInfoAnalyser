#ifndef BELT_1_H
#define BELT_1_H

#include "equipment.h"

class Belt_1 : public Equipment { // 魔法师[???]的腰带 Belt: 3
  public:
    Belt_1() {}
	void operator() (Character &model);
};

#endif // BELT_1_H
