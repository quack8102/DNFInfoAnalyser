#ifndef EARRING_9_H
#define EARRING_9_H

#include "equipment.h"

class Earring_9 : public Equipment { // 宽容之海 Earring: 11
  public:
    Earring_9() {}
	void operator() (Character &model);
};

#endif // EARRING_9_H
