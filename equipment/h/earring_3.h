#ifndef EARRING_3_H
#define EARRING_3_H

#include "equipment.h"

class Earring_3 : public Equipment { // 等离子操控者 Earring: 11
  public:
    Earring_3() {}
	void operator() (Character &model);
};

#endif // EARRING_3_H
