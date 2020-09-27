#ifndef MAGE_25_H
#define MAGE_25_H

#include "equipment.h"

class Mage_25 : public Equipment { // 飘零之花战矛
public:
	Mage_25(){}
	void operator() (Character &model);
};

#endif // MAGE_25_H
