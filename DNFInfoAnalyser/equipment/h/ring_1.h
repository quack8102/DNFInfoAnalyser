#ifndef RING_1_H
#define RING_1_H

#include "equipment.h"

class Ring_1 : public Equipment { // 寂静无言之露珠 Ring: 10
  public:
    Ring_1() {}
	void operator() (Character &model);
};

#endif // RING_1_H
