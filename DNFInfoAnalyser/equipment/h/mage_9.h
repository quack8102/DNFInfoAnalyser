#ifndef MAGE_9_H
#define MAGE_9_H

#include "equipment.h"

class Mage_9 : public Equipment { // 混沌之种 Mage: 5
  public:
    Mage_9() {}
	void operator() (Character &model);
};

#endif // MAGE_9_H
