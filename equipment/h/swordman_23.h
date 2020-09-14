#ifndef SWORDMAN_23_H
#define SWORDMAN_23_H

#include "equipment.h"

class Swordman_23 : public Equipment { // 星之海：巴德纳尔 Swordman: 5
  public:
    Swordman_23() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_23_H
