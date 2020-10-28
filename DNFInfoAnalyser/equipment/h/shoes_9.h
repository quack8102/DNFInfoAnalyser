#ifndef SHOES_9_H
#define SHOES_9_H

#include "equipment.h"

class Shoes_9 : public Equipment { // 巴尔：堕落之魂 Shoes: 4
  public:
    Shoes_9() {}
	void operator() (Character &model);
};

#endif // SHOES_9_H
