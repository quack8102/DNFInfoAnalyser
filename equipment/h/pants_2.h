#ifndef PANTS_2_H
#define PANTS_2_H

#include "equipment.h"

class Pants_2 : public Equipment { // 魅惑律动伦巴 Pants: 2
  public:
    Pants_2() {}
	void operator() (Character &model);
};

#endif // PANTS_2_H
