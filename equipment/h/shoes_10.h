#ifndef SHOES_10_H
#define SHOES_10_H

#include "equipment.h"

class Shoes_10 : public Equipment { // 自然之核 Shoes: 4
  public:
    Shoes_10() {}
	void operator() (Character &model);
};

#endif // SHOES_10_H
