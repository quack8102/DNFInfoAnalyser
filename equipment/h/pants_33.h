#ifndef PANTS_33_H
#define PANTS_33_H

#include "equipment.h"

class Pants_33 : public Equipment { // 无形：洛多斯的灵魂意志
public:
	Pants_33(){}
	void operator() (Character &model);
};

#endif // PANTS_33_H
