#ifndef SWORDMAN_7_H
#define SWORDMAN_7_H

#include "equipment.h"

class Swordman_7 : public Equipment { // 暗黑圣战之溯回：太刀 Swordman: 5
  public:
    Swordman_7() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_7_H
