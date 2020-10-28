#ifndef SHOES_12_H
#define SHOES_12_H

#include "equipment.h"

class Shoes_12 : public Equipment { // 奔流不息之银河 Shoes: 4
  public:
    Shoes_12() {}
	void operator() (Character &model);
};

#endif // SHOES_12_H
