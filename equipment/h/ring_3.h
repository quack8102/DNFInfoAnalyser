#ifndef RING_3_H
#define RING_3_H

#include "equipment.h"

class Ring_3 : public Equipment { // 祝福之风-西尔芙 Ring: 10
  public:
    Ring_3() {}
	void operator() (Character &model);
};

#endif // RING_3_H
