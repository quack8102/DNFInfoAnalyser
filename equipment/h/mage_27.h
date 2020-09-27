#ifndef MAGE_27_H
#define MAGE_27_H

#include "equipment.h"

class Mage_27 : public Equipment { // 飘零之花魔杖
public:
	Mage_27(){}
	void operator() (Character &model);
};

#endif // MAGE_27_H
