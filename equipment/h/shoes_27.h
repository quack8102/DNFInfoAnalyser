#ifndef SHOES_27_H
#define SHOES_27_H

#include "equipment.h"

class Shoes_27 : public Equipment { // 霸域英豪战靴 Shoes: 4
  public:
    Shoes_27() {}
	void operator() (Character &model);
};

#endif // SHOES_27_H
