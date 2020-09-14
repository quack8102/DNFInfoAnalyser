#ifndef EARRING_12_H
#define EARRING_12_H

#include "equipment.h"

class Earring_12 : public Equipment { // 无尽地狱黑暗之印 Earring: 11
  public:
    Earring_12() {}
	void operator() (Character &model);
};

#endif // EARRING_12_H
