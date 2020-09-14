#ifndef SWORDMAN_3_H
#define SWORDMAN_3_H

#include "equipment.h"

class Swordman_3 : public Equipment { // 信念徽章：自由 Swordman: 5
  public:
    Swordman_3() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_3_H
