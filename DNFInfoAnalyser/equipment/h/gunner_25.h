#ifndef GUNNER_25_H
#define GUNNER_25_H

#include "equipment.h"

class Gunner_25 : public Equipment { // 飘零之花左轮枪
public:
	Gunner_25(){}
	void operator() (Character &model);
};

#endif // GUNNER_25_H
