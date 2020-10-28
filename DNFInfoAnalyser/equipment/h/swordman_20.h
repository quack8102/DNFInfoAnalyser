#ifndef SWORDMAN_20_H
#define SWORDMAN_20_H

#include "equipment.h"

class Swordman_20 : public Equipment { // 夜语黑瞳光剑 Swordman: 5
  public:
    Swordman_20() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_20_H
