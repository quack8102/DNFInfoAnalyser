#ifndef SWORDMAN_18_H
#define SWORDMAN_18_H

#include "equipment.h"

class Swordman_18 : public Equipment { // 卡西姆的大剑 Swordman: 5
  public:
    Swordman_18() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_18_H
