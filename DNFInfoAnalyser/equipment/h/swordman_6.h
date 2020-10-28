#ifndef SWORDMAN_6_H
#define SWORDMAN_6_H

#include "equipment.h"

class Swordman_6 : public Equipment { // 界·夜语黑瞳太刀 Swordman: 5
  public:
    Swordman_6() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_6_H
