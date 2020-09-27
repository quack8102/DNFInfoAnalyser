#ifndef NECK_25_H
#define NECK_25_H

#include "equipment.h"

class Neck_25 : public Equipment { // 无欲之花
public:
	Neck_25(){}
	void operator() (Character &model);
};

#endif // NECK_25_H
