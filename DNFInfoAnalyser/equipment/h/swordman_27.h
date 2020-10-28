#ifndef SWORDMAN_27_H
#define SWORDMAN_27_H

#include "equipment.h"

class Swordman_27 : public Equipment { // 飘零之花钝器
public:
	Swordman_27(){}
	void operator() (Character &model);
};

#endif // SWORDMAN_27_H
