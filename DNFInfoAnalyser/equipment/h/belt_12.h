#ifndef BELT_12_H
#define BELT_12_H

#include "equipment.h"

class Belt_12 : public Equipment { // 奔流不息之狂风 Belt: 3
  public:
    Belt_12() {}
	void operator() (Character &model);
};

#endif // BELT_12_H
