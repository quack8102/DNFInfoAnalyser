#ifndef SWORDMAN_2_H
#define SWORDMAN_2_H

#include "equipment.h"

class Swordman_2 : public Equipment { // 暗黑圣战之溯回：短剑 Swordman: 5
  public:
    Swordman_2() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_2_H
