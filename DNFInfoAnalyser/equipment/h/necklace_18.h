#ifndef NECKLACE_18_H
#define NECKLACE_18_H

#include "equipment.h"

class Necklace_18 : public Equipment { // 无形青岩
public:
	Necklace_18(){}
	void operator() (Character &model);
};

#endif // NECKLACE_18_H
