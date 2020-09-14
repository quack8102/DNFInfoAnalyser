#ifndef NECKLACE_15_H
#define NECKLACE_15_H

#include "equipment.h"

class Necklace_15 : public Equipment { // 天御万物 Necklace: 8
  public:
    Necklace_15() {}
	void operator() (Character &model);
};

#endif // NECKLACE_15_H
