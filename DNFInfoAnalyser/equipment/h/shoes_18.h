#ifndef SHOES_18_H
#define SHOES_18_H

#include "equipment.h"

class Shoes_18 : public Equipment { // 崩溃世界的忧伤 Shoes: 4
  public:
    Shoes_18() {}
	void operator() (Character &model);
};

#endif // SHOES_18_H
