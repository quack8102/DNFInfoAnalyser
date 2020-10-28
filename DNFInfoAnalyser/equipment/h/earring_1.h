#ifndef EARRING_1_H
#define EARRING_1_H

#include "equipment.h"

class Earring_1 : public Equipment { // 永恒之海 Earring: 11
  public:
    Earring_1() {}
	void operator() (Character &model);
};

#endif // EARRING_1_H
