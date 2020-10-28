#ifndef SWORDMAN_14_H
#define SWORDMAN_14_H

#include "equipment.h"

class Swordman_14 : public Equipment { // 骚动的冥焰 Swordman: 5
  public:
    Swordman_14() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_14_H
