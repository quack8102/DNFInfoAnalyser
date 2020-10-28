#ifndef BELT_4_H
#define BELT_4_H

#include "equipment.h"

class Belt_4 : public Equipment { // 首席执行官裁决腰带 Belt: 3
  public:
    Belt_4() {}
	void operator() (Character &model);
};

#endif // BELT_4_H
