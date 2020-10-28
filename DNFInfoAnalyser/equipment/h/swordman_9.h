#ifndef SWORDMAN_9_H
#define SWORDMAN_9_H

#include "equipment.h"

class Swordman_9 : public Equipment { // 前瞻守卫者 Swordman: 5
  public:
    Swordman_9() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_9_H
