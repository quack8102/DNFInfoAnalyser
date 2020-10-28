#ifndef MAGE_8_H
#define MAGE_8_H

#include "equipment.h"

class Mage_8 : public Equipment { // 精灵浮风棍 Mage: 5
  public:
    Mage_8() {}
	void operator() (Character &model);
};

#endif // MAGE_8_H
