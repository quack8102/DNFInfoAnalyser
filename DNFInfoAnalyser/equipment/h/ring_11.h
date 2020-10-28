#ifndef RING_11_H
#define RING_11_H

#include "equipment.h"

class Ring_11 : public Equipment { // 碧水红潮 Ring: 10
  public:
    Ring_11() {}
	void operator() (Character &model);
};

#endif // RING_11_H
