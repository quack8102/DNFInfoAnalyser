#ifndef NECKLACE_12_H
#define NECKLACE_12_H

#include "equipment.h"

class Necklace_12 : public Equipment { // 先知者的预言 Necklace: 8
  public:
    Necklace_12() {}
	void operator() (Character &model);
};

#endif // NECKLACE_12_H
