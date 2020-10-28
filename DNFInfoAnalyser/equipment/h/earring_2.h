#ifndef EARRING_2_H
#define EARRING_2_H

#include "equipment.h"

class Earring_2 : public Equipment { // 时之魅影 Earring: 11
  public:
    Earring_2() {}
	void operator() (Character &model);
};

#endif // EARRING_2_H
