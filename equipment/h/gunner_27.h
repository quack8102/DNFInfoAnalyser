#ifndef GUNNER_27_H
#define GUNNER_27_H

#include "equipment.h"

class Gunner_27 : public Equipment { // 飘零之花步枪
public:
	Gunner_27(){}
	void operator() (Character &model);
};

#endif // GUNNER_27_H
