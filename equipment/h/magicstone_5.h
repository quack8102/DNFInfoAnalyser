#ifndef MAGICSTONE_5_H
#define MAGICSTONE_5_H

#include "equipment.h"

class Magicstone_5 : public Equipment { // 被困的时之沙 Magicstone: 12
  public:
    Magicstone_5() {}
	void operator() (Character &model);
};

#endif // MAGICSTONE_5_H
