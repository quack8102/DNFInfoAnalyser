#ifndef NECKLACE_10_H
#define NECKLACE_10_H

#include "equipment.h"

class Necklace_10 : public Equipment { // 精炼的混沌魔石项链 Necklace: 8
  public:
    Necklace_10() {}
	void operator() (Character &model);
};

#endif // NECKLACE_10_H
