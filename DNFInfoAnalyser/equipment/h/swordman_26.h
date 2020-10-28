#ifndef SWORDMAN_26_H
#define SWORDMAN_26_H

#include "equipment.h"

class Swordman_26 : public Equipment { // 飘零之花太刀
public:
	Swordman_26(){}
	void operator() (Character &model);
};

#endif // SWORDMAN_26_H
