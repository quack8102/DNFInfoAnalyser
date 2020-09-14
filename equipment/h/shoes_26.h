#ifndef SHOES_26_H
#define SHOES_26_H

#include "equipment.h"

class Shoes_26 : public Equipment { // 魔战无双短靴 Shoes: 4
  public:
    Shoes_26() {}
	void operator() (Character &model);
};

#endif // SHOES_26_H
