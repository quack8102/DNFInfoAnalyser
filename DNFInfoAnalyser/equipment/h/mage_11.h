#ifndef MAGE_11_H
#define MAGE_11_H

#include "equipment.h"

class Mage_11 : public Equipment { // 界·夜语黑瞳魔杖 Mage: 5
  public:
    Mage_11() {}
	void operator() (Character &model);
};

#endif // MAGE_11_H
