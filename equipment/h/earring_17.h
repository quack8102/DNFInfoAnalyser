#ifndef EARRING_17_H
#define EARRING_17_H

#include "equipment.h"

class Earring_17 : public Equipment { // 时空：腐蚀之黑色十字耳环 Earring: 11
  public:
    Earring_17() {}
	void operator() (Character &model);
};

#endif // EARRING_17_H
