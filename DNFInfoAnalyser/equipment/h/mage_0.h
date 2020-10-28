#ifndef MAGE_0_H
#define MAGE_0_H

#include "equipment.h"

class Mage_0 : public Equipment { // 夜语黑瞳矛 Mage: 5
  public:
    Mage_0() {}
	void operator() (Character &model);
};

#endif // MAGE_0_H
