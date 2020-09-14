#ifndef RING_7_H
#define RING_7_H

#include "equipment.h"

class Ring_7 : public Equipment { // 蓬勃生命的落幕 Ring: 10
  public:
    Ring_7() {}
	void operator() (Character &model);
};

#endif // RING_7_H
