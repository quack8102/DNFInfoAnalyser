#ifndef SHOES_5_H
#define SHOES_5_H

#include "equipment.h"

class Shoes_5 : public Equipment { // 赤地千里战靴 Shoes: 4
  public:
    Shoes_5() {}
	void operator() (Character &model);
};

#endif // SHOES_5_H
