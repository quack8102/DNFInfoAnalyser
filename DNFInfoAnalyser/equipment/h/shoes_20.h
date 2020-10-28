#ifndef SHOES_20_H
#define SHOES_20_H

#include "equipment.h"

class Shoes_20 : public Equipment { // 逝魔之风速短靴 Shoes: 4
  public:
    Shoes_20() {}
	void operator() (Character &model);
};

#endif // SHOES_20_H
