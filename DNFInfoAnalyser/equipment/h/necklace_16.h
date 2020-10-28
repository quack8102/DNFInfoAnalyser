#ifndef NECKLACE_16_H
#define NECKLACE_16_H

#include "equipment.h"

class Necklace_16 : public Equipment { // 杀戮之决 Necklace: 8
  public:
    Necklace_16() {}
	void operator() (Character &model);
};

#endif // NECKLACE_16_H
