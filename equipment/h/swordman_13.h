#ifndef SWORDMAN_13_H
#define SWORDMAN_13_H

#include "equipment.h"

class Swordman_13 : public Equipment { // 哈蒂-赎月者 Swordman: 5
  public:
    Swordman_13() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_13_H
