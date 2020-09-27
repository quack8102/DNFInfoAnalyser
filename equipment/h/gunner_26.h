#ifndef GUNNER_26_H
#define GUNNER_26_H

#include "equipment.h"

class Gunner_26 : public Equipment { // 飘零之花自动手枪
public:
	Gunner_26(){}
	void operator() (Character &model);
};

#endif // GUNNER_26_H
