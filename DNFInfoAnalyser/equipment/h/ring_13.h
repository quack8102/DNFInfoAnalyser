#ifndef RING_13_H
#define RING_13_H

#include "equipment.h"

class Ring_13 : public Equipment { // 无欲：奈克斯的梦幻黑暗
public:
	Ring_13(){}
	void operator() (Character &model);
};

#endif // RING_13_H
