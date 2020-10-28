#ifndef SHOES_3_H
#define SHOES_3_H

#include "equipment.h"

class Shoes_3 : public Equipment { // 死亡阴影长靴 Shoes: 4
  public:
    Shoes_3() {}
	void operator() (Character &model);
};

#endif // SHOES_3_H
