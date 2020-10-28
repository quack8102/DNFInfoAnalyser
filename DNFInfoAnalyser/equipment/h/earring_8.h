#ifndef EARRING_8_H
#define EARRING_8_H

#include "equipment.h"

class Earring_8 : public Equipment { // 军神的古怪耳环 Earring: 11
  public:
    Earring_8() {}
	void operator() (Character &model);
};

#endif // EARRING_8_H
