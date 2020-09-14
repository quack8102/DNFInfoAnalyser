#ifndef NECKLACE_13_H
#define NECKLACE_13_H

#include "equipment.h"

class Necklace_13 : public Equipment { // 全能霸域 Necklace: 8
  public:
    Necklace_13() {}
	void operator() (Character &model);
};

#endif // NECKLACE_13_H
