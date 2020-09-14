#ifndef PANTS_13_H
#define PANTS_13_H

#include "equipment.h"

class Pants_13 : public Equipment { // 命运的抉择 Pants: 2
  public:
    Pants_13() {}
	void operator() (Character &model);
};

#endif // PANTS_13_H
