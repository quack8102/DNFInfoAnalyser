#ifndef MAGICSTONE_7_H
#define MAGICSTONE_7_H

#include "equipment.h"

class Magicstone_7 : public Equipment { // 狂乱之天灾降临 Magicstone: 12
  public:
    Magicstone_7() {}
	void operator() (Character &model);
};

#endif // MAGICSTONE_7_H
