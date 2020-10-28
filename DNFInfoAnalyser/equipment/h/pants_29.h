#ifndef PANTS_29_H
#define PANTS_29_H

#include "equipment.h"

class Pants_29 : public Equipment { // 无形：奈克斯的灵魂仪服
public:
	Pants_29(){}
	void operator() (Character &model);
};

#endif // PANTS_29_H
