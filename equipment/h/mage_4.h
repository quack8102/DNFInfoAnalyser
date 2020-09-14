#ifndef MAGE_4_H
#define MAGE_4_H

#include "equipment.h"

class Mage_4 : public Equipment { // 吟唱：不灭之魂 Mage: 5
  public:
    Mage_4() {}
	void operator() (Character &model);
};

#endif // MAGE_4_H
