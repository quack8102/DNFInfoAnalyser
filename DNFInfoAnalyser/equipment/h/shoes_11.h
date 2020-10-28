#ifndef SHOES_11_H
#define SHOES_11_H

#include "equipment.h"

class Shoes_11 : public Equipment { // 千链锁灵战靴 Shoes: 4
  public:
    Shoes_11() {}
	void operator() (Character &model);
};

#endif // SHOES_11_H
