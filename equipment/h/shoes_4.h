#ifndef SHOES_4_H
#define SHOES_4_H

#include "equipment.h"

class Shoes_4 : public Equipment { // 首席执行官裁决长靴 Shoes: 4
  public:
    Shoes_4() {}
	void operator() (Character &model);
};

#endif // SHOES_4_H
