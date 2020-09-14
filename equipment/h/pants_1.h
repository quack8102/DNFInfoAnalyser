#ifndef PANTS_1_H
#define PANTS_1_H

#include "equipment.h"

class Pants_1 : public Equipment { // 魔法师[???]的护腿 Pants: 2
  public:
    Pants_1() {}
	void operator() (Character &model);
};

#endif // PANTS_1_H
