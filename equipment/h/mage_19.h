#ifndef MAGE_19_H
#define MAGE_19_H

#include "equipment.h"

class Mage_19 : public Equipment { // 银月的祝福 Mage: 5
  public:
    Mage_19() {}
	void operator() (Character &model);
};

#endif // MAGE_19_H
