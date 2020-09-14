#ifndef BELT_13_H
#define BELT_13_H

#include "equipment.h"

class Belt_13 : public Equipment { // 正义的抉择 Belt: 3
  public:
    Belt_13() {}
	void operator() (Character &model);
};

#endif // BELT_13_H
