#ifndef MAGE_13_H
#define MAGE_13_H

#include "equipment.h"

class Mage_13 : public Equipment { // 火焰地狱 Mage: 5
  public:
    Mage_13() {}
	void operator() (Character &model);
};

#endif // MAGE_13_H
