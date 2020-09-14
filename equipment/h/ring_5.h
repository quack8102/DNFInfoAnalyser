#ifndef RING_5_H
#define RING_5_H

#include "equipment.h"

class Ring_5 : public Equipment { // 次元穿越者之印 Ring: 10
  public:
    Ring_5() {}
	void operator() (Character &model);
};

#endif // RING_5_H
