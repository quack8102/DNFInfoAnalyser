#ifndef MAGE_28_H
#define MAGE_28_H

#include "equipment.h"

class Mage_28 : public Equipment { // 飘零之花法杖
public:
	Mage_28(){}
	void operator() (Character &model);
};

#endif // MAGE_28_H
