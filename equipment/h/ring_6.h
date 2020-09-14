#ifndef RING_6_H
#define RING_6_H

#include "equipment.h"

class Ring_6 : public Equipment { // 命运的捉弄 Ring: 10
  public:
    Ring_6() {}
	void operator() (Character &model);
};

#endif // RING_6_H
