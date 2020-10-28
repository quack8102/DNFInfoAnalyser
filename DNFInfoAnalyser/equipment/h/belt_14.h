#ifndef BELT_14_H
#define BELT_14_H

#include "equipment.h"

class Belt_14 : public Equipment { // 宁静苍翠之水 Belt: 3
  public:
    Belt_14() {}
	void operator() (Character &model);
};

#endif // BELT_14_H
