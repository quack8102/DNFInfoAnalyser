#ifndef MAGICSTONE_9_H
#define MAGICSTONE_9_H

#include "equipment.h"

class Magicstone_9 : public Equipment { // 轮回：周而复始的时间 Magicstone: 12
  public:
    Magicstone_9() {}
	void operator() (Character &model);
};

#endif // MAGICSTONE_9_H
