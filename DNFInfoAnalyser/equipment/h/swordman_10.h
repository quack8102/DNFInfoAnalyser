#ifndef SWORDMAN_10_H
#define SWORDMAN_10_H

#include "equipment.h"

class Swordman_10 : public Equipment { // 夜语黑瞳钝器 Swordman: 5
  public:
    Swordman_10() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_10_H
