#ifndef SHOES_22_H
#define SHOES_22_H

#include "equipment.h"

class Shoes_22 : public Equipment { // 天御风行战甲 Shoes: 4
  public:
    Shoes_22() {}
	void operator() (Character &model);
};

#endif // SHOES_22_H
