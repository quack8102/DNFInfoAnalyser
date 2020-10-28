#ifndef MAGE_22_H
#define MAGE_22_H

#include "equipment.h"

class Mage_22 : public Equipment { // 暗黑圣战之溯回：扫把 Mage: 5
  public:
    Mage_22() {}
	void operator() (Character &model);
};

#endif // MAGE_22_H
