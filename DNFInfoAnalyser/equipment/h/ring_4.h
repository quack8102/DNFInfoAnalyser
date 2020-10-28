#ifndef RING_4_H
#define RING_4_H

#include "equipment.h"

class Ring_4 : public Equipment { // 支配黑暗之环 Ring: 10
  public:
    Ring_4() {}
	void operator() (Character &model);
};

#endif // RING_4_H
