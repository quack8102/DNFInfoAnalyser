#ifndef BELT_6_H
#define BELT_6_H

#include "equipment.h"

class Belt_6 : public Equipment { // 守护战士之苦难 Belt: 3
  public:
    Belt_6() {}
	void operator() (Character &model);
};

#endif // BELT_6_H
