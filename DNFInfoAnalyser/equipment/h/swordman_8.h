#ifndef SWORDMAN_8_H
#define SWORDMAN_8_H

#include "equipment.h"

class Swordman_8 : public Equipment { // 太极天帝剑 Swordman: 5
  public:
    Swordman_8() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_8_H
