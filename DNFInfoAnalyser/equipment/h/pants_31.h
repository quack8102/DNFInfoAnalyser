#ifndef PANTS_31_H
#define PANTS_31_H

#include "equipment.h"

class Pants_31 : public Equipment { // 无形：卢克西的灵魂狂气
public:
	Pants_31(){}
	void operator() (Character &model);
};

#endif // PANTS_31_H
