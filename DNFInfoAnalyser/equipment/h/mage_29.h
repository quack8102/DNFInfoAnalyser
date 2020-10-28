#ifndef MAGE_29_H
#define MAGE_29_H

#include "equipment.h"

class Mage_29 : public Equipment { // 飘零之花扫把
public:
	Mage_29(){}
	void operator() (Character &model);
};

#endif // MAGE_29_H
