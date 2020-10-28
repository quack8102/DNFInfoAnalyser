#ifndef RING_14_H
#define RING_14_H

#include "equipment.h"

class Ring_14 : public Equipment { // 无欲：暗杀者的梦幻痕迹
public:
	Ring_14(){}
	void operator() (Character &model);
};

#endif // RING_14_H
