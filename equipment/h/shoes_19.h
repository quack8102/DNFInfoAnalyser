#ifndef SHOES_19_H
#define SHOES_19_H

#include "equipment.h"

class Shoes_19 : public Equipment { // 黑暗幽灵紫杉长靴 Shoes: 4
  public:
    Shoes_19() {}
	void operator() (Character &model);
};

#endif // SHOES_19_H
