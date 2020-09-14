#ifndef SHOES_1_H
#define SHOES_1_H

#include "equipment.h"

class Shoes_1 : public Equipment { // 魔法师[???]的长靴 Shoes: 4
  public:
    Shoes_1() {}
	void operator() (Character &model);
};

#endif // SHOES_1_H
