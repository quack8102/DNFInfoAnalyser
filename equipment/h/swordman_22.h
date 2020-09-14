#ifndef SWORDMAN_22_H
#define SWORDMAN_22_H

#include "equipment.h"

class Swordman_22 : public Equipment { // 暗黑圣战之溯回：光剑 Swordman: 5
  public:
    Swordman_22() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_22_H
