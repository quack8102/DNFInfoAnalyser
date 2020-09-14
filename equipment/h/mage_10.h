#ifndef MAGE_10_H
#define MAGE_10_H

#include "equipment.h"

class Mage_10 : public Equipment { // 夜语黑瞳魔杖 Mage: 5
  public:
    Mage_10() {}
	void operator() (Character &model);
};

#endif // MAGE_10_H
