#ifndef BELT_22_H
#define BELT_22_H

#include "equipment.h"

class Belt_22 : public Equipment { // 魔战无双腰带 Belt: 3
  public:
    Belt_22() {}
	void operator() (Character &model);
};

#endif // BELT_22_H
