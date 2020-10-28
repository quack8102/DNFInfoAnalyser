#ifndef EARRING_14_H
#define EARRING_14_H

#include "equipment.h"

class Earring_14 : public Equipment { // 命运挑战者 Earring: 11
  public:
    Earring_14() {}
	void operator() (Character &model);
};

#endif // EARRING_14_H
