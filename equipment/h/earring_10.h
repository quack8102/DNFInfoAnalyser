#ifndef EARRING_10_H
#define EARRING_10_H

#include "equipment.h"

class Earring_10 : public Equipment { // 时之矛盾 Earring: 11
  public:
    Earring_10() {}
	void operator() (Character &model);
};

#endif // EARRING_10_H
