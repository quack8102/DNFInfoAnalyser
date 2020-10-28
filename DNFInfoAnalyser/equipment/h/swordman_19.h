#ifndef SWORDMAN_19_H
#define SWORDMAN_19_H

#include "equipment.h"

class Swordman_19 : public Equipment { // 神之意象 Swordman: 5
  public:
    Swordman_19() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_19_H
