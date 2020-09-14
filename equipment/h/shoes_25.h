#ifndef SHOES_25_H
#define SHOES_25_H

#include "equipment.h"

class Shoes_25 : public Equipment { // 千蛛碎影之利齿战靴 Shoes: 4
  public:
    Shoes_25() {}
	void operator() (Character &model);
};

#endif // SHOES_25_H
