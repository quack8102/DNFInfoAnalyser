#ifndef NECKLACE_0_H
#define NECKLACE_0_H

#include "equipment.h"

class Necklace_0 : public Equipment { // 肯那兹：精神燎原之火 Necklace: 8
  public:
    Necklace_0() {}
	void operator() (Character &model);
};

#endif // NECKLACE_0_H
