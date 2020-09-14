#ifndef RING_12_H
#define RING_12_H

#include "equipment.h"

class Ring_12 : public Equipment { // 骸麒之戒 Ring: 10
  public:
    Ring_12() {}
	void operator() (Character &model);
};

#endif // RING_12_H
