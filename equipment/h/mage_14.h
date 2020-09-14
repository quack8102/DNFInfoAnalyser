#ifndef MAGE_14_H
#define MAGE_14_H

#include "equipment.h"

class Mage_14 : public Equipment { // 魔力之泉：加斯达利亚 Mage: 5
  public:
    Mage_14() {}
	void operator() (Character &model);
};

#endif // MAGE_14_H
