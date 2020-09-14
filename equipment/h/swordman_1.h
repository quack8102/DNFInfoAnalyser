#ifndef SWORDMAN_1_H
#define SWORDMAN_1_H

#include "equipment.h"

class Swordman_1 : public Equipment { // 界·夜语黑瞳短剑 Swordman: 5
  public:
    Swordman_1() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_1_H
