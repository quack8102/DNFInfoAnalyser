#ifndef MAGE_18_H
#define MAGE_18_H

#include "equipment.h"

class Mage_18 : public Equipment { // 世界树的根须 Mage: 5
  public:
    Mage_18() {}
	void operator() (Character &model);
};

#endif // MAGE_18_H
