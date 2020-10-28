#ifndef BELT_17_H
#define BELT_17_H

#include "equipment.h"

class Belt_17 : public Equipment { // 亡灵之帐腰带 Belt: 3
  public:
    Belt_17() {}
	void operator() (Character &model);
};

#endif // BELT_17_H
