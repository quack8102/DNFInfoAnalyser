#ifndef EARRING_0_H
#define EARRING_0_H

#include "equipment.h"

class Earring_0 : public Equipment { // 军神的心之所念 Earring: 11
  public:
    Earring_0() {}
	void operator() (Character &model);
};

#endif // EARRING_0_H
