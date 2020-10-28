#ifndef MAGE_21_H
#define MAGE_21_H

#include "equipment.h"

class Mage_21 : public Equipment { // 界·夜语黑瞳扫把 Mage: 5
  public:
    Mage_21() {}
	void operator() (Character &model);
};

#endif // MAGE_21_H
