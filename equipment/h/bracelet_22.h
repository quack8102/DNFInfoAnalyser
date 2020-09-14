#ifndef BRACELET_22_H
#define BRACELET_22_H

#include "equipment.h"

class Bracelet_22 : public Equipment { // 噙毒手套 Bracelet: 7
  public:
    Bracelet_22() {}
	void operator() (Character &model);
};

#endif // BRACELET_22_H
