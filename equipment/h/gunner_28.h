#ifndef GUNNER_28_H
#define GUNNER_28_H

#include "equipment.h"

class Gunner_28 : public Equipment { // 飘零之花手炮
public:
	Gunner_28(){}
	void operator() (Character &model);
};

#endif // GUNNER_28_H
