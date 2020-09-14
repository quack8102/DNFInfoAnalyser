#ifndef SWORDMAN_21_H
#define SWORDMAN_21_H

#include "equipment.h"

class Swordman_21 : public Equipment { // 界·夜语黑瞳光剑 Swordman: 5
  public:
    Swordman_21() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_21_H
