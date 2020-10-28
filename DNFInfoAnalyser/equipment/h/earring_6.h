#ifndef EARRING_6_H
#define EARRING_6_H

#include "equipment.h"

class Earring_6 : public Equipment { // 命运反抗者 Earring: 11
  public:
    Earring_6() {}
	void operator() (Character &model);
};

#endif // EARRING_6_H
