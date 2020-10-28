#ifndef MAGE_5_H
#define MAGE_5_H

#include "equipment.h"

class Mage_5 : public Equipment { // 夜语黑瞳棍棒 Mage: 5
  public:
    Mage_5() {}
	void operator() (Character &model);
};

#endif // MAGE_5_H
