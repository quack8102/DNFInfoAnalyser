#ifndef EARRING_5_H
#define EARRING_5_H

#include "equipment.h"

class Earring_5 : public Equipment { // 次元穿越者之星 Earring: 11
  public:
    Earring_5() {}
	void operator() (Character &model);
};

#endif // EARRING_5_H
