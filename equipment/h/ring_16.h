#ifndef RING_16_H
#define RING_16_H

#include "equipment.h"

class Ring_16 : public Equipment { // 无欲：守门人的梦幻邪念
public:
	Ring_16(){}
	void operator() (Character &model);
};

#endif // RING_16_H
