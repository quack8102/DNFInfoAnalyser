#ifndef MAGE_2_H
#define MAGE_2_H

#include "equipment.h"

class Mage_2 : public Equipment { // 暗黑圣战之溯回：矛 Mage: 5
  public:
    Mage_2() {}
	void operator() (Character &model);
};

#endif // MAGE_2_H
