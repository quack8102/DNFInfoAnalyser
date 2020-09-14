#ifndef MAGE_12_H
#define MAGE_12_H

#include "equipment.h"

class Mage_12 : public Equipment { // 暗黑圣战之溯回：魔杖 Mage: 5
  public:
    Mage_12() {}
	void operator() (Character &model);
};

#endif // MAGE_12_H
