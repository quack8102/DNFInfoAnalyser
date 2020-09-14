#ifndef SWORDMAN_12_H
#define SWORDMAN_12_H

#include "equipment.h"

class Swordman_12 : public Equipment { // 暗黑圣战之溯回：钝器 Swordman: 5
  public:
    Swordman_12() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_12_H
