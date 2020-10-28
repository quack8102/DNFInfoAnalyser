#ifndef MAGE_23_H
#define MAGE_23_H

#include "equipment.h"

class Mage_23 : public Equipment { // 世界树之精灵 Mage: 5
  public:
    Mage_23() {}
	void operator() (Character &model);
};

#endif // MAGE_23_H
