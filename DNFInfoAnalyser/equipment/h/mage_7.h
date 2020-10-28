#ifndef MAGE_7_H
#define MAGE_7_H

#include "equipment.h"

class Mage_7 : public Equipment { // 暗黑圣战之溯回：棍棒 Mage: 5
  public:
    Mage_7() {}
	void operator() (Character &model);
};

#endif // MAGE_7_H
