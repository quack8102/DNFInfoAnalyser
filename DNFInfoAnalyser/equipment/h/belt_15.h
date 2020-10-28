#ifndef BELT_15_H
#define BELT_15_H

#include "equipment.h"

class Belt_15 : public Equipment { // 黑暗幽灵紫杉腰带 Belt: 3
  public:
    Belt_15() {}
	void operator() (Character &model);
};

#endif // BELT_15_H
