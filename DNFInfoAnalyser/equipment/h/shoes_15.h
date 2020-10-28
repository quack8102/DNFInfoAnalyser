#ifndef SHOES_15_H
#define SHOES_15_H

#include "equipment.h"

class Shoes_15 : public Equipment { // 堕入地狱之脚 Shoes: 4
  public:
    Shoes_15() {}
	void operator() (Character &model);
};

#endif // SHOES_15_H
