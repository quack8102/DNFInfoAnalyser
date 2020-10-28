#ifndef COAT_30_H
#define COAT_30_H

#include "equipment.h"

class Coat_30 : public Equipment { // 千链锁灵战甲 Coat: 1
  public:
    Coat_30() {}
	void operator() (Character &model);
};

#endif // COAT_30_H
