#ifndef NECKLACE_17_H
#define NECKLACE_17_H

#include "equipment.h"

class Necklace_17 : public Equipment { // 逝魔之痕 Necklace: 8
  public:
    Necklace_17() {}
	void operator() (Character &model);
};

#endif // NECKLACE_17_H
