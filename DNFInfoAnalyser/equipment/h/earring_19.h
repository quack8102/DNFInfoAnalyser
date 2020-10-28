#ifndef EARRING_19_H
#define EARRING_19_H

#include "equipment.h"

class Earring_19 : public Equipment { // 转世：回溯的生命 Earring: 11
  public:
    Earring_19() {}
	void operator() (Character &model);
};

#endif // EARRING_19_H
