#ifndef SWORDMAN_0_H
#define SWORDMAN_0_H

#include "equipment.h"

class Swordman_0 : public Equipment { // 夜语黑瞳短剑 Swordman: 5
  public:
    Swordman_0() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_0_H
