#ifndef SHOES_8_H
#define SHOES_8_H

#include "equipment.h"

class Shoes_8 : public Equipment { // 遮天蔽日长靴 Shoes: 4
  public:
    Shoes_8() {}
	void operator() (Character &model);
};

#endif // SHOES_8_H
