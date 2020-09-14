#ifndef RING_10_H
#define RING_10_H

#include "equipment.h"

class Ring_10 : public Equipment { // 精炼的遗忘魔石戒指 Ring: 10
  public:
    Ring_10() {}
	void operator() (Character &model);
};

#endif // RING_10_H
