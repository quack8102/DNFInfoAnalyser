#ifndef MAGE_1_H
#define MAGE_1_H

#include "equipment.h"

class Mage_1 : public Equipment { // 界·夜语黑瞳矛 Mage: 5
  public:
    Mage_1() {}
	void operator() (Character &model);
};

#endif // MAGE_1_H
