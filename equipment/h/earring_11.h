#ifndef EARRING_11_H
#define EARRING_11_H

#include "equipment.h"

class Earring_11 : public Equipment { // 电磁能量传送者 Earring: 11
  public:
    Earring_11() {}
	void operator() (Character &model);
};

#endif // EARRING_11_H
