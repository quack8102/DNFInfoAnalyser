#ifndef BELT_10_H
#define BELT_10_H

#include "equipment.h"

class Belt_10 : public Equipment { // 碎钢之牙 Belt: 3
  public:
    Belt_10() {}
	void operator() (Character &model);
};

#endif // BELT_10_H
