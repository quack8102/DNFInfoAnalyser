#ifndef MAGE_16_H
#define MAGE_16_H

#include "equipment.h"

class Mage_16 : public Equipment { // 界·夜语黑瞳法杖 Mage: 5
  public:
    Mage_16() {}
	void operator() (Character &model);
};

#endif // MAGE_16_H
