#ifndef SHOES_24_H
#define SHOES_24_H

#include "equipment.h"

class Shoes_24 : public Equipment { // 誓血之盟战靴 Shoes: 4
  public:
    Shoes_24() {}
	void operator() (Character &model);
};

#endif // SHOES_24_H
