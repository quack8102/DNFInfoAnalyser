#ifndef MAGE_6_H
#define MAGE_6_H

#include "equipment.h"

class Mage_6 : public Equipment { // 界·夜语黑瞳棍棒 Mage: 5
  public:
    Mage_6() {}
	void operator() (Character &model);
};

#endif // MAGE_6_H
