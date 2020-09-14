#ifndef SWORDMAN_16_H
#define SWORDMAN_16_H

#include "equipment.h"

class Swordman_16 : public Equipment { // 界·夜语黑瞳巨剑 Swordman: 5
  public:
    Swordman_16() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_16_H
