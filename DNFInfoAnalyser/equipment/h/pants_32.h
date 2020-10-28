#ifndef PANTS_32_H
#define PANTS_32_H

#include "equipment.h"

class Pants_32 : public Equipment { // 无形：守门人的灵魂甲胄
public:
	Pants_32(){}
	void operator() (Character &model);
};

#endif // PANTS_32_H
