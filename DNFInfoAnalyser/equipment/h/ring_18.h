#ifndef RING_18_H
#define RING_18_H

#include "equipment.h"

class Ring_18 : public Equipment { // 无念剑环
public:
	Ring_18(){}
	void operator() (Character &model);
};

#endif // RING_18_H
