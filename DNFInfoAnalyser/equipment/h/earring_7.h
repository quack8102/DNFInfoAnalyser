#ifndef EARRING_7_H
#define EARRING_7_H

#include "equipment.h"

class Earring_7 : public Equipment { // 心痛如绞的诀别 Earring: 11
  public:
    Earring_7() {}
	void operator() (Character &model);
};

#endif // EARRING_7_H
