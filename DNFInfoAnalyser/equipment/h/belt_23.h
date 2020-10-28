#ifndef BELT_23_H
#define BELT_23_H

#include "equipment.h"

class Belt_23 : public Equipment { // 霸域英豪腰带 Belt: 3
  public:
    Belt_23() {}
	void operator() (Character &model);
};

#endif // BELT_23_H
