#ifndef RING_8_H
#define RING_8_H

#include "equipment.h"

class Ring_8 : public Equipment { // 维度粉碎戒指 Ring: 10
  public:
    Ring_8() {}
	void operator() (Character &model);
};

#endif // RING_8_H
