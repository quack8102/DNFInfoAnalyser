#ifndef MAGE_26_H
#define MAGE_26_H

#include "equipment.h"

class Mage_26 : public Equipment { // 飘零之花棍棒
public:
	Mage_26(){}
	void operator() (Character &model);
};

#endif // MAGE_26_H
