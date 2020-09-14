#ifndef SWORDMAN_5_H
#define SWORDMAN_5_H

#include "equipment.h"

class Swordman_5 : public Equipment { // 夜语黑瞳太刀 Swordman: 5
  public:
    Swordman_5() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_5_H
