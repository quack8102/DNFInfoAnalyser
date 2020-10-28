#ifndef MAGE_24_H
#define MAGE_24_H

#include "equipment.h"

class Mage_24 : public Equipment { // 纯白的祈祷 Mage: 5
  public:
    Mage_24() {}
	void operator() (Character &model);
};

#endif // MAGE_24_H
