#ifndef SHOES_16_H
#define SHOES_16_H

#include "equipment.h"

class Shoes_16 : public Equipment { // 次元漫步者长靴 Shoes: 4
  public:
    Shoes_16() {}
	void operator() (Character &model);
};

#endif // SHOES_16_H
