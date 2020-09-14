#ifndef EARRING_16_H
#define EARRING_16_H

#include "equipment.h"

class Earring_16 : public Equipment { // 腐蚀之黑色十字耳环 Earring: 11
  public:
    Earring_16() {}
	void operator() (Character &model);
};

#endif // EARRING_16_H
