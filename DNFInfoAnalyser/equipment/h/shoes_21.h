#ifndef SHOES_21_H
#define SHOES_21_H

#include "equipment.h"

class Shoes_21 : public Equipment { // 黄泉之风战靴 Shoes: 4
  public:
    Shoes_21() {}
	void operator() (Character &model);
};

#endif // SHOES_21_H
