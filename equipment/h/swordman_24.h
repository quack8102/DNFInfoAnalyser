#ifndef SWORDMAN_24_H
#define SWORDMAN_24_H

#include "equipment.h"

class Swordman_24 : public Equipment { // 赤光剑路易纳斯 Swordman: 5
  public:
    Swordman_24() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_24_H
