#ifndef SWORDMAN_25_H
#define SWORDMAN_25_H

#include "equipment.h"

class Swordman_25 : public Equipment { // 飘零之花短剑
public:
	Swordman_25(){}
	void operator() (Character &model);
};

#endif // SWORDMAN_25_H
