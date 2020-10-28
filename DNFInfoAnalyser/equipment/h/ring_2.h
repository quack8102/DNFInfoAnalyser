#ifndef RING_2_H
#define RING_2_H

#include "equipment.h"

class Ring_2 : public Equipment { // 红兔之祝福 Ring: 10
  public:
    Ring_2() {}
	void operator() (Character &model);
};

#endif // RING_2_H
