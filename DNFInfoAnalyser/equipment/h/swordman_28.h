#ifndef SWORDMAN_28_H
#define SWORDMAN_28_H

#include "equipment.h"

class Swordman_28 : public Equipment { // 飘零之花巨剑
public:
	Swordman_28(){}
	void operator() (Character &model);
};

#endif // SWORDMAN_28_H
