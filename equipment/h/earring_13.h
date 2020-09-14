#ifndef EARRING_13_H
#define EARRING_13_H

#include "equipment.h"

class Earring_13 : public Equipment { // 次元流星坠 Earring: 11
  public:
    Earring_13() {}
	void operator() (Character &model);
};

#endif // EARRING_13_H
