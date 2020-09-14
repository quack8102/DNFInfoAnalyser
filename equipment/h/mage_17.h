#ifndef MAGE_17_H
#define MAGE_17_H

#include "equipment.h"

class Mage_17 : public Equipment { // 暗黑圣战之溯回：法杖 Mage: 5
  public:
    Mage_17() {}
	void operator() (Character &model);
};

#endif // MAGE_17_H
