#ifndef PANTS_15_H
#define PANTS_15_H

#include "equipment.h"

class Pants_15 : public Equipment { // 驱散黑暗短裤 Pants: 2
  public:
    Pants_15() {}
	void operator() (Character &model);
};

#endif // PANTS_15_H
