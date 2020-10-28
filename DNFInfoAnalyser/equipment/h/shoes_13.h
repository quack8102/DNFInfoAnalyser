#ifndef SHOES_13_H
#define SHOES_13_H

#include "equipment.h"

class Shoes_13 : public Equipment { // 守护的抉择 Shoes: 4
  public:
    Shoes_13() {}
	void operator() (Character &model);
};

#endif // SHOES_13_H
