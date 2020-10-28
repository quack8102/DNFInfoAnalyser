#ifndef SWORDMAN_29_H
#define SWORDMAN_29_H

#include "equipment.h"

class Swordman_29 : public Equipment { // 飘零之花光剑
public:
	Swordman_29(){}
	void operator() (Character &model);
};

#endif // SWORDMAN_29_H
