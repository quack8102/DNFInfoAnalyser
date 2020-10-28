#ifndef RING_17_H
#define RING_17_H

#include "equipment.h"

class Ring_17 : public Equipment { // 无欲：洛多斯的梦幻根源
public:
	Ring_17(){}
	void operator() (Character &model);
};

#endif // RING_17_H
