#ifndef MAGE_20_H
#define MAGE_20_H

#include "equipment.h"

class Mage_20 : public Equipment { // 夜语黑瞳扫把 Mage: 5
  public:
    Mage_20() {}
	void operator() (Character &model);
};

#endif // MAGE_20_H
