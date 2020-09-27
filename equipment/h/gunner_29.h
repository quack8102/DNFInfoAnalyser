#ifndef GUNNER_29_H
#define GUNNER_29_H

#include "equipment.h"

class Gunner_29 : public Equipment { // 飘零之花手弩
public:
	Gunner_29(){}
	void operator() (Character &model);
};

#endif // GUNNER_29_H
