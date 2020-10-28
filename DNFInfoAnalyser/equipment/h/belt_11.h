#ifndef BELT_11_H
#define BELT_11_H

#include "equipment.h"

class Belt_11 : public Equipment { // 千链锁灵腰带 Belt: 3
  public:
    Belt_11() {}
	void operator() (Character &model);
};

#endif // BELT_11_H
