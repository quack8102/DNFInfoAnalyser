#ifndef MAGICSTONE_3_H
#define MAGICSTONE_3_H

#include "equipment.h"

class Magicstone_3 : public Equipment { // 电光能量支配者 Magicstone: 12
  public:
    Magicstone_3() {}
	void operator() (Character &model);
};

#endif // MAGICSTONE_3_H
