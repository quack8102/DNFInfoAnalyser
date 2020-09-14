#ifndef SHOES_17_H
#define SHOES_17_H

#include "equipment.h"

class Shoes_17 : public Equipment { // 悲喜交加 Shoes: 4
  public:
    Shoes_17() {}
	void operator() (Character &model);
};

#endif // SHOES_17_H
