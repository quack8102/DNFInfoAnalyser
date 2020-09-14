#ifndef EARRING_4_H
#define EARRING_4_H

#include "equipment.h"

class Earring_4 : public Equipment { // 永恒地狱黑暗之印 Earring: 11
  public:
    Earring_4() {}
	void operator() (Character &model);
};

#endif // EARRING_4_H
