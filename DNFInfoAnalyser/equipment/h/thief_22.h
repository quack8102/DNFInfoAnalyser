#ifndef THIEF_22_H
#define THIEF_22_H

#include "equipment.h"

class Thief_22 : public Equipment { // 飘零之花手杖
public:
	Thief_22(){}
	void operator() (Character &model);
};

#endif // THIEF_22_H
