#ifndef MAGE_15_H
#define MAGE_15_H

#include "equipment.h"

class Mage_15 : public Equipment { // 夜语黑瞳法杖 Mage: 5
  public:
    Mage_15() {}
	void operator() (Character &model);
};

#endif // MAGE_15_H
