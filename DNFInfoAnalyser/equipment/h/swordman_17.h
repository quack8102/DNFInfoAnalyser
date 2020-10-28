#ifndef SWORDMAN_17_H
#define SWORDMAN_17_H

#include "equipment.h"

class Swordman_17 : public Equipment { // 暗黑圣战之溯回：巨剑 Swordman: 5
  public:
    Swordman_17() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_17_H
