#ifndef RING_0_H
#define RING_0_H

#include "equipment.h"

class Ring_0 : public Equipment { // 盖柏：完美的均衡 Ring: 10
  public:
    Ring_0() {}
	void operator() (Character &model);
};

#endif // RING_0_H
