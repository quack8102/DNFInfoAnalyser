#ifndef RING_9_H
#define RING_9_H

#include "equipment.h"

class Ring_9 : public Equipment { // 冰雪公主的霜语戒指 Ring: 10
  public:
    Ring_9() {}
	void operator() (Character &model);
};

#endif // RING_9_H
