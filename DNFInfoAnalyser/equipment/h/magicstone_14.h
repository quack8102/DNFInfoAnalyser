#ifndef MAGICSTONE_14_H
#define MAGICSTONE_14_H

#include "equipment.h"

class Magicstone_14 : public Equipment { // 灵魂掠夺者
public:
	Magicstone_14(){}
	void operator() (Character &model);
};

#endif // MAGICSTONE_14_H
