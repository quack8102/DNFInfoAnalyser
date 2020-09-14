#ifndef BELT_3_H
#define BELT_3_H

#include "equipment.h"

class Belt_3 : public Equipment { // 死亡阴影腰带 Belt: 3
  public:
    Belt_3() {}
	void operator() (Character &model);
};

#endif // BELT_3_H
