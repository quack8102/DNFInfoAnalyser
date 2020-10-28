#ifndef SWORDMAN_15_H
#define SWORDMAN_15_H

#include "equipment.h"

class Swordman_15 : public Equipment { // 夜语黑瞳巨剑 Swordman: 5
  public:
    Swordman_15() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_15_H
