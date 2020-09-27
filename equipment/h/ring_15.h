#ifndef RING_15_H
#define RING_15_H

#include "equipment.h"

class Ring_15 : public Equipment { // 无欲：卢克西的梦幻约定
public:
	Ring_15(){}
	void operator() (Character &model);
};

#endif // RING_15_H
