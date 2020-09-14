#ifndef MAGE_3_H
#define MAGE_3_H

#include "equipment.h"

class Mage_3 : public Equipment { // 歼灵灭魂矛 Mage: 5
  public:
    Mage_3() {}
	void operator() (Character &model);
};

#endif // MAGE_3_H
