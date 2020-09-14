#ifndef EARRING_18_H
#define EARRING_18_H

#include "equipment.h"

class Earring_18 : public Equipment { // 轮回：腐蚀之黑色十字耳环 Earring: 11
  public:
    Earring_18() {}
	void operator() (Character &model);
};

#endif // EARRING_18_H
