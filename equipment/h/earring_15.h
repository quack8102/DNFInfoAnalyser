#ifndef EARRING_15_H
#define EARRING_15_H

#include "equipment.h"

class Earring_15 : public Equipment { // 悲剧人生的归寂 Earring: 11
  public:
    Earring_15() {}
	void operator() (Character &model);
};

#endif // EARRING_15_H
