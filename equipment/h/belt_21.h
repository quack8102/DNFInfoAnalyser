#ifndef BELT_21_H
#define BELT_21_H

#include "equipment.h"

class Belt_21 : public Equipment { // 千蛛碎影之蛛刺腰带 Belt: 3
  public:
    Belt_21() {}
	void operator() (Character &model);
};

#endif // BELT_21_H
