#ifndef EARRING_20_H
#define EARRING_20_H

#include "equipment.h"

class Earring_20 : public Equipment { // 窥视未来耳环 Earring: 11
  public:
    Earring_20() {}
	void operator() (Character &model);
};

#endif // EARRING_20_H
